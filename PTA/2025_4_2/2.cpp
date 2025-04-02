#include <iostream>
#include <vector>

using Map = std::vector<std::vector<int>>;

int getLength(int row, int col, Map& map, Map& memo){
    if(memo[row][col] != -1){
        return memo[row][col];
    }
    int length = 0;
    if (row > 0 && map[row][col] < map[row - 1][col])
    {
        length = std::max(length, getLength(row - 1, col, map, memo));
    }
    if (row < map.size() - 1 && map[row][col] < map[row + 1][col])
    {
        length = std::max(length, getLength(row + 1, col, map, memo));
    }
    if(col > 0 && map[row][col] < map[row][col - 1]){
        length = std::max(length, getLength(row, col - 1, map, memo));
    }
    if(col < map[0].size() - 1 && map[row][col] < map[row][col + 1]){
        length = std::max(length, getLength(row, col + 1, map, memo));
    }
    memo[row][col] = length + 1;
    return memo[row][col];
}
int main(int argc, const char** argv) {
    Map map;
    Map memo;
    int length = 0;
    int row, col;
    std::cin >> row >> col;
    map.resize(row);
    memo.resize(row);
    for (size_t i = 0; i < row; i++)
    {
        map[i].resize(col);
        memo[i].resize(col);
        for (size_t j = 0; j < col; j++)
        {
            int t;
            std::cin >> t;
            map[i][j] = t;
            memo[i][j] = -1;
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            length = std::max(length, getLength(i, j, map, memo));
        }
    }
    std::cout << length;

    return 0;
}