# Dynamic Array (C++)

A C++ implementation of a dynamic array data structure that supports resizing and common array operations.

## Overview
This project demonstrates how a dynamic array manages memory manually, expanding and contracting as elements are added or removed.

The implementation separates the data structure logic from the driver program to keep the design modular and easy to test.

## Project Structure
- `src/` — Dynamic array implementation and driver
- `data/` — Input file used to test array operations

## Features
- Dynamic resizing
- Element insertion and removal
- Index-based access
- File-driven input processing

## Build & Run
Compile the project from the root directory:

```bash
g++ src/*.cpp -std=c++17 -o dynamic_array

