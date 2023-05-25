CC = /usr/bin/gcc

CFLAGS = -Wall -g -O2 -Werror -std=c11 -Wno-unused-function

EXE_HARDWARE = exe_hardware

SRC_DIR = ./src

# debug
COMMON = $(SRC_DIR)/common/print.c $(SRC_DIR)/common/convert.c

# hardware
CPU =$(SRC_DIR)/hardware/cpu/mmu.c $(SRC_DIR)/hardware/cpu/isa.c
MEMORY = $(SRC_DIR)/hardware/memory/dram.c

# main
TEST_HARDWARE = $(SRC_DIR)/tests/test_hardware.c

.PHONY:hardware
hardware:
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(COMMON) $(CPU) $(MEMORY) $(DISK) $(TEST_HARDWARE) -o $(EXE_HARDWARE)
	./$(EXE_HARDWARE)

run:
	./$(EXE_HARDWARE)
