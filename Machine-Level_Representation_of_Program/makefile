# Define the compiler
CC = /usr/bin/gcc

# Define the compiler flags
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

# Define the output executable
EXE = program

# Define the source directory
SRC_DIR = ./src

# Define the source files
CODE = $(SRC_DIR)/main.c $(SRC_DIR)/memory/instruction.c

# Include directories
INCLUDES = -I$(SRC_DIR) -I$(SRC_DIR)/cpu -I$(SRC_DIR)/memory

# Default target
all: $(EXE)

# Build the executable
$(EXE): $(CODE)
	$(CC) $(CFLAGS) $(INCLUDES) $(CODE) -o $(EXE)

# Clean
clean:
	rm -f $(EXE)
