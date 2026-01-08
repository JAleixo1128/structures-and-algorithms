#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

class Maze {

private:
    unsigned int seed;
    int rows;
    int cols;

    std::vector<std::vector<int>> grid;


    std::vector<std::vector<bool>> visited;


public:
    
    Maze(unsigned int seed,int rows, int cols);
    std::vector<std::pair<int,int>> getValidNeighbors(int row, int col);
    void removeWall(int currentRow, int currentCol, int nextRow, int nextCol);

    bool inBounds(int row, int col);
    void mazeGenerator();
    void exportFile(const std::string& filename);

};
#endif // MAZE_H


