// Memory Management Unit
#include "../../headers/common.h"
#include "../../headers/cpu.h"
#include "../../headers/memory.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t va2pa(uint64_t vaddr, core_t *cr) {
  return vaddr % PHYSICAL_MEMORY_SPACE;
}
