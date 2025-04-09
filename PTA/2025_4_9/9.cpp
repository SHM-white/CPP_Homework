#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int main(){
    std::string str;
    std::getline(std::cin, str);
    std::stringstream ss{str};
    std::vector<int> heights;
    while (!ss.eof())
    {
        int t;
        ss >> t;
        heights.push_back(t);
    }
    std::vector<int> dp(heights.size(), 1);
    int result = 0;
    for (size_t i = 1; i < dp.size(); i++)
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