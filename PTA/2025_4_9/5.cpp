#include <iostream>
#include <vector>
#include <climits>
using Map = std::vector<std::vector<int>>;

int main(){
    int n;
    std::cin >> n;
    Map map(n + 1, std::vector<int>(n + 1, 0));
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = i + 1; j <= n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    std::vector<int> dp(n + 1, INT_MAX / 4);
    dp[0] = 0;
    dp[1] = 0;
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = i + 1; j <= n; j++)
        {
            dp[j] = std::min(dp[j], dp[i] + map[i][j]);
        }
    }
    std::cout << dp[n] << std::endl;
}