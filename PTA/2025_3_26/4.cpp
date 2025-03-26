#include <iostream>
#include <set>
int main(){
    std::set<int> nums;
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        nums.insert(t);
    }
    std::cout << nums.size() << std::endl;
    for (auto i : nums){
        std::cout << i << " ";
    }
}