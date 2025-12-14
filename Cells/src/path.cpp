#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool findPath(vector<vector<int>> &grid, int x, int y, int target) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
        return false;
    if (grid[x][y] == target) return true;

    int curr = grid[x][y];
    grid[x][y] = -1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] >= curr)
            if (findPath(grid, nx, ny, target)) return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 4) return 1;

    ifstream file(argv[1]);
    int M = stoi(argv[2]), N = stoi(argv[3]);
    vector<vector<int>> grid(M, vector<int>(N));
    int minVal = 101, maxVal = -1, minX, minY, maxX, maxY;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            file >> grid[i][j];
            if (grid[i][j] < minVal) minVal = grid[i][j], minX = i, minY = j;
            if (grid[i][j] > maxVal) maxVal = grid[i][j], maxX = i, maxY = j;
        }

    cout << minX + 1 << " " << minY + 1 << " " << maxX + 1 << " " << maxY + 1 << " "
         << (findPath(grid, minX, minY, maxVal) ? "yes" : "no") << endl;

    return 0;
}

