#include <iostream>
#include <vector>

const int MAX_SIZE = 1e5 + 9;

std::vector<std::vector<int>> CreateMap(){
    return std::vector<std::vector<int>>(MAX_SIZE, std::vector<int>(11, 0));
}

int main(int argc, const char** argv) {
    int n;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    while (n != 0)
    {
        auto map = CreateMap();
        auto dp = CreateMap();
        int MAX_T = 0;
        for (size_t i = 0; i < n; i++)
        {
            int x, t;
            std::cin >> x >> t;
            map[t][x] += 1;
            MAX_T = std::max(MAX_T, t);
        }
        dp[0] = map[0];
        int result = 0;
        for (int i = 1; i <= MAX_T; i++)
        {
            for (int j = std::max(5 - i, 0); j <= std::min(5 + i, 10); j++)
            {
                for (int k = -1; k < 2; k++)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][std::min(10, std::max(j + k, 0))]);
                }
                dp[i][j] += map[i][j];
                result = std::max(result, dp[i][j]);
            }
        }
        std::cout << result << std::endl;
        std::cin >> n;
    }
    return 0;
}