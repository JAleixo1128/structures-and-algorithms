# Hash Table Implementation

A C++ implementation of a hash table with file-based input and testing.
The project demonstrates core hash table operations including insertion,
lookup, and collision handling.

## Overview

This project implements a custom hash table data structure from scratch.
It supports reading data from input files, storing key–value pairs,
and executing operations through a driver program.

The focus is on correctness, efficiency, and clear separation between
data structure logic and program execution.

## Project Structure

- `src/`
  - `hash_table.cpp` / `hash_table.h`  
    Core hash table implementation
  - `main.cpp`  
    Driver program that reads input and executes hash operations

- `data/`
  - `Hash.txt`  
    Input file containing data to insert into the table
  - `test_1.txt`  
    Test cases for validating behavior

## Features

- Custom hash function
- Collision handling
- File-driven input
- Modular design separating implementation and execution

## Building and Running

From the `src` directory:

```bash
g++ *.cpp -std=c++17 -o hash_table
./hash_table

