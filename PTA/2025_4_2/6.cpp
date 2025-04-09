#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 'L') {
        return;
    }
    grid[x][y] = '.'; // 标记为已访问
    dfs(grid, x + 1, y, n, m);
    dfs(grid, x - 1, y, n, m);
    dfs(grid, x, y + 1, n, m);
    dfs(grid, x, y - 1, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int islandCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'L') {
                ++islandCount;
                dfs(grid, i, j, n, m);
            }
        }
    }

    cout << islandCount << endl;
    return 0;
}
