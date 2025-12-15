
# Linked List Implementation

A C++ implementation of a singly linked list with file-based testing.
The project demonstrates core linked list operations and pointer-based
memory management.

## Overview

This project builds a custom linked list data structure from scratch.
Nodes are dynamically allocated and connected using pointers, allowing
the list to grow and shrink at runtime.

A driver program reads commands from input files to test correctness
and behavior across multiple scenarios.

## Project Structure

- `linked_list.cpp` / `linked_list.h`  
  Linked list implementation and public interface

- `node.cpp` / `node.h`  
  Node definition and low-level pointer management

- `main.cpp`  
  Driver program that processes input files and executes operations

- `test1.txt`, `test2.txt`, `test3.txt`  
  Input files used to validate list behavior

## Features

- Dynamic node allocation
- Insertion and removal operations
- Traversal and output
- File-driven testing
- Separation of concerns between nodes, list logic, and execution

## Building and Running

From the project directory:

```bash
g++ *.cpp -std=c++17 -o linkedlist
./linkedlist
