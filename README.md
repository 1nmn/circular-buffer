# Circular Buffer

## Overview

This project implements a fixed-size integer ring buffer in C.
The buffer supports the following operations:

- `cb_init(size)` – initialize a buffer with given size.
- `cb_push(value)` – add a value to the buffer.
- `cb_pop()` – remove and return the oldest value from the buffer.
- `cb_peek()` – view the oldest value without removing it.
- `cb_is_empty()` / `cb_is_full()` – check buffer state.

The buffer uses an internal array with head/tail indexing to support wraparound.
The project includes a **test harness** (`main.c`) that shows the functionality.

---

## Directory Structure

```
C:.
│   .gitignore
│   LICENSE
│   Makefile
│   README.md
│
├───github
│   └───workflows
│           build.yml
│
├───inc
│       circular_buffer.h
│
└───src
        circular_buffer.c
        main.c
```

#### `inc/circular_buffer.h`
- Declares the public API for the circular buffer.  
- Contains function prototypes, the `circular_buffer_t` type, and comments explaining each function.

#### `src/circular_buffer.c`
- Implements all buffer operations: `push`, `pop`, `peek`, `is_empty`, `is_full`.  
- Handles wraparound and overwrites the buffer when full.  

#### `src/main.c`
- Test harness demonstrating the circular buffer.  
- Pushes and pops values, prints the internal buffer state, and verifies full/empty.

#### `Makefile`
- Builds the project into the `build/` folder.  
- Supports `make all`, `make run`, and `make clean`.

---

### Build and Run Instructions

```bash
# Compile the project
make all

# Run the executable
make run

# Remove build artifacts
make clean