#include <iostream>
#include <vector>

using Map = std::vector<std::vector<int>>;

int main(){
    int n;
    std::cin >> n;
    Map map(n + 2, std::vector<int>(n + 1, 0));
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            std::cin >> map[i][j];
        }
    }
    Map dp(n + 2, std::vector<int>(n + 1, 0));
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1]) + map[i][j];
        }
    }
    int result = 0;
    for (size_t i = 1; i <= n; i++)
    {
        result = std::max(result, dp[n][i]);
    }
    std::cout << result;
}