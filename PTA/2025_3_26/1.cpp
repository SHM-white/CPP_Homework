#include <iostream>
#include <deque>
int main(){
    std::deque<int> nums;
    int n, m;
    std::cin >> n >> m;
    nums.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    while (nums.size() > 1)
    {
        for (size_t i = 0; i < m; i++)
        {
            nums.push_back(nums.front());
            nums.pop_front();
        }
        nums.pop_back();
    }
    std::cout << nums[0];
}