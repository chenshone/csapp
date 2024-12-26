#ifndef dram_guard
#define dram_guard

#include<stdint.h>

#define MM_LEN 1000

uint8_t mm[MM_LEN]; // physical memory

void write64bits_dram(uint64_t paddr, uint64_t data);
uint64_t read64bits_dram(uint64_t paddr);

void print_stack();
void print_register();

#endif