# Structures and Algorithms in C++

A curated collection of C++ projects exploring real-world implementations of core data structures and algorithms.  
Each project was designed to demonstrate not just how these structures work — but why they matter, when to use them, and how their performance impacts software systems.

This repository showcases custom-built implementations without relying on STL container internals.  
All logic, memory management, and algorithmic behavior is written from scratch to demonstrate full control and understanding of underlying mechanisms.

---

##  Highlights

- Manual pointer and memory management
- Dynamic storage structures with amortized analysis
- Recursive and backtracking search patterns
- Graph traversal, maze solving, and pathfinding
- Hashing strategies and collision resolution
- Balanced search trees including custom Red-Black Tree implementation
- Priority-based scheduling using binary heaps
- Real dataset processing using maps and set operations

---

##  Project Structure

| Project | Focus Area | Folder |
|--------|------------|--------|
| Animals Simulation | OOP foundations & polymorphism | `Animals-Simulation` |
|  Dynamic Array | Manual resize logic & amortized insertion | `Dynamic-Array` |
|  Linked List | Pointer network, iteration & deep copying | `Linked-List` |
|  Recursion Algorithms | Recursive logic, tree search patterns | `Recursion-Algorithms` |
|  Backtracking Engine | Constraint solving & decision reversal | `Backtracking-Engine` |
|  Maze Solver | BFS/DFS pathfinding & grid traversal | `Maze-Solver` |
|  Graph Toolkit | Adjacency lists, BFS, DFS & traversal | `Graph-Toolkit` |
|  Hash Tables | Hashing, probing & chain collision handling | `Hash-Tables` |
|  Priority Queue + Heap | Binary heap implementation | `Priority-Queue-and-Heap` |
|  Sets and Maps Engine | Data indexing, querying, and parsing | `Sets-and-Maps` |
|  Cells (Grid Ops) | Flood-fill, blob detection, adjacency | `Cells` |
|  Balancing Act | BST and Red-Black Tree balancing | `Balancing-Act` |

---

##  Build Instructions

All projects are standard ISO C++ (C++17 or higher recommended).

```bash
g++ -std=c++17 main.cpp -o run
./run
