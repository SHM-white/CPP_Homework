#include <iostream>
#include <vector>
#include <climits>
int main(){
    int n;
    std::cin >> n;

    std::vector<int> stones(n + 1);
    for (size_t i = 1; i <= n; i++)
    {
        std::cin >> stones[i];
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, INT_MAX / 4));
    std::vector<std::vector<int>> totalCost(n + 1, std::vector<int>(n + 1, INT_MAX / 4));
    for (size_t count = 1; count <= n; count++)
    {
        for (size_t i = 1; i + count - 1 <= n; i++)
        {
            if(count > 1){
                for (size_t j = i; j < i + count - 1; j++)
                {
                    dp[i][i + count - 1] = std::min(dp[i][j] + dp[j + 1][i + count - 1], dp[i][i + count - 1]);
                    totalCost[i][i + count - 1] = std::min(totalCost[i][j] + totalCost[j + 1][i + count - 1] + dp[i][i + count - 1], totalCost[i][i + count - 1]);
                }
            }
            else{
                dp[i][i] = stones[i];
                totalCost[i][i] = 0;
            }
            
            // 
        }
        
    }
    std::cout << totalCost[1][n] << std::endl;
    
}