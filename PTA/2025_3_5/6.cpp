#include <iostream>
#include <algorithm>
#include <vector>
int main(){
    std::vector<int> nums;
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        nums.push_back(t);
    }
    std::sort(nums.begin(), nums.end(), [](int a, int b){ return a < b; });
    std::cout << nums[2] << std::endl;
}