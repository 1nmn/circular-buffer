# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinc -g

# Directories
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,build/%.o,$(SRC))

# Target executable
TARGET = build/main

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
build:
	mkdir -p build

# Clean build folder
clean:
	rm -rf build

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run build