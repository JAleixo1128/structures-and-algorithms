#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int countBlobCells(vector<vector<int>> &grid, int x, int y, int connType) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
        return 0;

    grid[x][y] = 0; 
    int cellCount = 1; 

    
    int dx4[] = {-1, 1, 0, 0};
    int dy4[] = {0, 0, -1, 1};

    int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int *dx = connType == 4 ? dx4 : dx8;
    int *dy = connType == 4 ? dy4 : dy8;
    int directions = connType == 4 ? 4 : 8;

    for (int i = 0; i < directions; i++) {
        cellCount += countBlobCells(grid, x + dx[i], y + dy[i], connType);
    }
    return cellCount;
}

int main(int argc, char *argv[]) {
     if (argc != 7) {
        cerr << "Usage: ./cells <filename> <rows> <cols> <startX> <startY> <connType>" << endl;
        return 1;
    }

    string filename = argv[1];
    int rows = stoi(argv[2]);
    int cols = stoi(argv[3]);
    int startX = stoi(argv[4]) - 1; 
    int startY = stoi(argv[5]) - 1; 
    int connType = stoi(argv[6]);


    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }
    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            file >> grid[i][j];

    file.close();

    int result = countBlobCells(grid, startX, startY, connType);
    cout << result << endl;

    return 0;
}



