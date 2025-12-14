
# Balancing Act (C++)

A C++ project exploring tree-based data structures with a focus on maintaining balance during insert and remove operations.

## Overview
This project implements and tests multiple tree structures, including:
- A standard **Binary Search Tree (BST)**
- A **Left-Leaning Red-Black Tree (LLRB)**

The implementation demonstrates how balanced trees maintain performance by enforcing structural constraints during modifications.

## Project Structure
- `src/` — C++ source and header files
- `data/` — Input files used to build and modify trees

## Test Files
- `file.txt` — Initial tree construction input
- `test_1.txt` — Insertion test cases
- `test_1_remove.txt` — Removal and rebalancing tests

## Concepts Demonstrated
- Binary search trees
- Tree rotations and rebalancing
- Insert and remove operations
- File-based input processing
- Modular C++ design

## Build & Run
Compile the project from the root directory:

```bash
g++ src/*.cpp -std=c++17 -o balancing_act
