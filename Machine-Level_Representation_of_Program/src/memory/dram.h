#pragma once
#include<stdint.h>

#define MM_LEN 1000

uint8_t mm[MM_LEN]; // physical memory

void write64bits_dram(uint64_t paddr, uint64_t data);
uint64_t read64bits_dram(uint64_t paddr);
