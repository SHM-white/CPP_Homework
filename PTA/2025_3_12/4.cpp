#include <iostream>
#include <map>
int main(){
    int n;
    std::cin >> n;
    std::map<int, int> nums;
    for (int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        nums[input] = 1;
    }
    std::cout << nums.size() << std::endl;
    for (auto i = nums.begin(); i != nums.end(); i++)
    {
        std::cout << i->first << " ";
    }
    
    
}