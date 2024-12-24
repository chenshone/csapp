#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t uint2float(uint32_t u) {
  if (u == 0x0)
    return 0x0;

  int n = 31; // 最高位1的位置
  while (n >= 0 && (((u >> n) & 0x1) == 0))
    n--;

  uint32_t f;            // fraction
  uint32_t e;            // exponent
  if (u <= 0x00ffffff) { //<= 0000 0000 1.111 1111 1111 1111 1111 1111
    // no need rounding
    uint32_t mask = 0xffffffff >> (32 - n);
    f = (u & mask) << (23 - n); // 对齐到小数点后23位
    e = n + 127;

    return (e << 23) | f;

  } else { // >= 0000 0001 0000 0000 0000 0000 0000 0000
    // need rounding
    uint64_t a = 0; // expand to 64 bit for situations like 0xffffffff
    a += u;

    uint32_t g = (a >> (n - 23)) & 0x1;
    uint32_t r = (a >> (n - 24)) & 0x1;
    uint32_t s = 0x0;

    for (int i = 0; i < n - 24; ++i) {
      s |= (a >> i) & 0x1;
    }

    // compute carry
    a >>= n - 23;
    /*
    Rounding Rules
    +-------+-------+-------+-------+
    |   G   |   R   |   S   |       |
    +-------+-------+-------+-------+
    |   0   |   0   |   0   |   +0  | round down
    |   0   |   0   |   1   |   +0  | round down
    |   0   |   1   |   0   |   +0  | round down
    |   0   |   1   |   1   |   +1  | round up
    |   1   |   0   |   0   |   +0  | round down
    |   1   |   0   |   1   |   +0  | round down
    |   1   |   1   |   0   |   +1  | round up
    |   1   |   1   |   1   |   +1  | round up
    +-------+-------+-------+-------+
    carry = R & (G | S) by K-Map
    */

    if ((r & (g | s)) == 0x1)
      a += 1;

    // check carry
    if ((a >> 23) == 0x1) { // 0 1.??? ???? ???? ???? ????
      f = a & 0x007fffff;
      e = n + 127;
      return (e << 23) | f;
    } else if ((a >> 23) == 0x2) { // 1 0.000 0000 0000 0000
      e = n + 1 + 127;
      return e << 23;
    }
  }
  // inf as default error
  return 0x7f800000;
}

// 用联合体来避免严格别名问题
typedef union {
  float f;
  uint32_t u;
} FloatUnion;

int main() {
  uint32_t uf;
  FloatUnion fu;

  for (uint32_t u = 0x00ffffff; u <= 0xffffffff; ++u) {
    uf = uint2float(u);
    fu.f = (float)u;

    if (uf != fu.u) {
      printf("fail\n");
      return 0;
    }
  }

  printf("pass\n");
  return 0;
}