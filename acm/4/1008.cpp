#include <iostream>
#include <vector>

const long MAX_SIZE = 1e6 + 9;


int main(){
    std::vector<std::vector<int>> nums;
    std::vector<std::vector<int>> dp;
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        nums.resize(n + 1);
        dp.resize(n + 1);
        nums[0].clear();
        nums[0].resize(k + 1, 0);
        dp[0].clear();
        dp[0].resize(k + 1, 0);
        for (size_t i = 1; i <= n; i++)
        {
            nums[i].clear();
            nums[i].resize(k + 1);
            dp[i].clear();
            dp[i].resize(k + 1, 0);
            for (size_t j = 1; j <= k; j++)
            {
                std::cin >> nums[i][j];
            }
        }
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= k; j++)
            {
                dp[i][j] = std::max(dp[i - 1][j] + nums[i][j], dp[i][j - 1]);
            }
            
        }
        std::cout << dp[n][k];
    }
    
}