# Define the compiler
CC = /usr/bin/gcc

# Define the compiler flags
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

# Define the output executable
EXE = uint2float

# Define the source files
SRC = uint2float.c

# Default target
all: $(EXE)

# Build the executable
$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

# Clean
clean:
	rm -f $(EXE)
