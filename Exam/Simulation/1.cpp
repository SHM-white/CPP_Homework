#include <iostream>
#include <vector>
int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    int zeroP;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> nums[i];
        if(nums[i] == 0){
            zeroP = i;
        }
    }
    if(k >= 2){
        std::cout << "Yes" << std::endl;
        return 0;
    }
    std::cin >> nums[zeroP];
    bool y = false;
    for (size_t i = 0; i < n - 1; i++)
    {
        y |= nums[i] > nums[i + 1];
    }
    std::cout << (y ? "Yes" : "No") << std::endl;
    
}