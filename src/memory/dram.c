#include "dram.h"
#include "../cpu/mmu.h"
#include "../cpu/register.h"
#include <stdint.h>
#include <stdio.h>

#define SRAM_CACHE_SETTING 0

uint64_t read64bits_dram(uint64_t paddr) {
  if (SRAM_CACHE_SETTING == 1) {
    return 0x0;
  }

  uint64_t val = 0x0;
  for (int i = 0; i < 8; i++)
    val += (((uint64_t)mm[paddr + i]) << (i * 8));
  return val;
}
void write64bits_dram(uint64_t paddr, uint64_t data) {
  if (SRAM_CACHE_SETTING == 1) {
    return;
  }

  for (int i = 0; i < 8; i++)
    mm[paddr + i] = (data >> (i * 8)) & 0xff;
}

void print_register() {
  printf("rax = %16llx\trbx = %16llx\trcx = %16llx\trdx = %16llx\n", reg.rax,
         reg.rbx, reg.rcx, reg.rdx);
  printf("rsi = %16llx\trdi = %16llx\trbp = %16llx\trsp = %16llx\n", reg.rsi,
         reg.rdi, reg.rbp, reg.rsp);
  printf("rip = %16llx\n", reg.rip);
}

void print_stack() {
  int n = 10;

  uint64_t *high = (uint64_t *)&mm[va2pa(reg.rsp)];
  // high = &high[n];
  high += n;

  uint64_t rsp_start = reg.rsp + n * 8;
  for (int i = 0; i < 2 * n; i++) {
    uint64_t *ptr = (uint64_t *)(high - i);
    printf("0x%016llx: %16llx", rsp_start, (uint64_t)*ptr);
    rsp_start -= 8;

    if (i == n) {
      printf(" <== rsp");
    }
    printf("\n");
  }
}
