# Backtracking Engine (C++)

A collection of classic constraint-satisfaction problems implemented in C++ using backtracking techniques.

## Problems Included
- **N-Queens** — Places queens on a chessboard so that none attack each other.
- **Sudoku Solver** — Solves Sudoku puzzles using recursive backtracking.
- **Sujiko Solver** — Solves a numeric constraint puzzle by exploring valid configurations.

## Input Files
The Sudoku and Sujiko solvers support different difficulty levels:
- `puzzle_easy.txt`
- `puzzle_medium.txt`
- `puzzle_hard.txt`

## Concepts Demonstrated
- Recursive backtracking
- Constraint checking
- State exploration and pruning
- File-based input handling

## Build & Run
Compile with:
```bash
g++ *.cpp -std=c++17 -o solver

