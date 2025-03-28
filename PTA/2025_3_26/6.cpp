#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
int main(int argc, const char** argv) {
    int t;
    std::cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        std::map<std::string, std::pair<int, int>> nums;
        //color, count, first_order
        int n;
        std::cin >> n;
        for (size_t j = 0; j < n; j++)
        {
            std::string color;
            std::cin >> color;
            nums[color].first++;
            nums[color].second == 0 ? nums[color].second = j + 1: NULL;
        }
        using ColorCountResult = std::pair<std::string, std::pair<int, int>>;
        std::vector<ColorCountResult> results;
        for (auto i = nums.begin(); i != nums.end(); i++){
            results.push_back(*i);
        }
        std::sort(results.begin(), results.end(), [](const ColorCountResult &r1, const ColorCountResult &r2)
                  { return r1.second.second < r2.second.second; });
        for (auto& i : results){
            std::cout << i.first << " " << i.second.first << std::endl;
        }
    }
    
}