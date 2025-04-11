#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int main(){
    std::string str;
    std::getline(std::cin, str);
    std::stringstream ss{str};
    std::vector<long long> heights;
    long long t;
    while (ss >> t) // 修改数据读取方式
    {
        heights.push_back(t);
    }
    std::vector<long long> dp(heights.size(), 1);
    long long result = 0;
    for (size_t i = 0; i < dp.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(heights[i] <= heights[j]){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        result = std::max(result, dp[i]);
    }
    std::cout << result << std::endl;
}