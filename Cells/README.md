
# Cells (C++)

A collection of small, focused C++ programs that solve grid-based and cell-based problems.

Each directory contains a standalone implementation designed to explore a specific computational task involving cells, coordinates, or paths.

## Included Programs
- **blobs** — Detects and processes connected regions in a grid.
- **cells** — Performs cell-based grid analysis.
- **eval** — Evaluates grid-derived expressions or configurations.
- **in2pos** — Converts structured input into positional data.
- **path** — Computes valid paths through a grid structure.

## Concepts Demonstrated
- Grid traversal
- Coordinate systems
- Input parsing
- Problem decomposition
- Standalone C++ program design

## Build & Run
Each program is compiled independently.

Example:
```bash
g++ src/blobs/blobs.cpp -std=c++17 -o blobs
./blobs
