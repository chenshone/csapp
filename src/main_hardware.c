#include "headers/common.h"
#include "headers/cpu.h"
#include "headers/memory.h"
#include <stdio.h>
#include <string.h>

#define MAX_NUM_INSTRUCTION_CYCLE 100

static void TestString2Uint();

// symbols from isa and sram
void print_register(core_t *cr);
void print_stack(core_t *cr);

int main() {
  TestString2Uint();
  return 0;
}
static void TestString2Uint() {
  const char *nums[12] = {"0",
                          "-0",
                          "0x0",
                          "1234",
                          "0x1234",
                          "0xabcd",
                          "-0xabcd",
                          "-1234",
                          "2147483647",
                          "-2147483648",
                          "0x8000000000000000",
                          "0xffffffffffffffff"};

  for (int i = 0; i < 12; i++) {
    printf("%s -> 0x%llx\n", nums[i], string2uint(nums[i]));
  }
}
