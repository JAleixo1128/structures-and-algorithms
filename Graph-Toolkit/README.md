# Graph Toolkit

A C++ graph processing utility supporting multiple graph representations and file-based input.

## Features
- Adjacency list representation
- Adjacency matrix representation
- Graph construction from input files
- DOT file output for visualization

## Files
- `adjacency_list.h` — adjacency list graph structure
- `adjacency_matrix.h` — adjacency matrix graph structure
- `main.cpp` — program entry point
- `data/*.txt` — sample graph inputs
- `*.dot` — generated visualization output

## Running
```bash
g++ src/*.cpp -std=c++17 -o graph_tool
./graph_tool data/test_1.txt

