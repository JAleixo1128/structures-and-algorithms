#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void clearBlob(vector<vector<int>> &grid, int x, int y, int connType) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
        return;

    grid[x][y] = 0;
    int dx4[] = {-1, 1, 0, 0};
    int dy4[] = {0, 0, -1, 1};
    int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int *dx = connType == 4 ? dx4 : dx8;
    int *dy = connType == 4 ? dy4 : dy8;
    int directions = connType == 4 ? 4 : 8;

    for (int i = 0; i < directions; i++)
        clearBlob(grid, x + dx[i], y + dy[i], connType);
}

int main(int argc, char *argv[]) {
    if (argc != 5) return 1;

    ifstream file(argv[1]);
    int M = stoi(argv[2]), N = stoi(argv[3]), connType = stoi(argv[4]);
    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            file >> grid[i][j];

    int blobCount = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 1) {
                blobCount++;
                clearBlob(grid, i, j, connType);
            }

    cout << blobCount << endl;
    return 0;
}

