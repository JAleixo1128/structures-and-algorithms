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

mkdir -p Animals-Simulation/src Animals-Simulation/include Animals-Simulation/data
mkdir -p Dynamic-Array/src Dynamic-Array/include Dynamic-Array/data
mkdir -p Linked-List/src Linked-List/include Linked-List/data
mkdir -p Recursion-Algorithms/src Recursion-Algorithms/include Recursion-Algorithms/data
mkdir -p Backtracking-Engine/src Backtracking-Engine/include Backtracking-Engine/data
mkdir -p Maze-Solver/src Maze-Solver/include Maze-Solver/data
mkdir -p Graph-Toolkit/src Graph-Toolkit/include Graph-Toolkit/data
mkdir -p Hash-Tables/src Hash-Tables/include Hash-Tables/data
mkdir -p Priority-Queue-and-Heap/src Priority-Queue-and-Heap/include Priority-Queue-and-Heap/data
mkdir -p Sets-and-Maps/src Sets-and-Maps/include Sets-and-Maps/data
mkdir -p Cells/src Cells/include Cells/data
mkdir -p Balancing-Act/src Balancing-Act/include Balancing-Act/data


##  Build Instructions

All projects are standard ISO C++ (C++17 or higher recommended).

```bash
g++ -std=c++17 main.cpp -o run
./run
