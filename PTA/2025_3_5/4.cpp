#include <iostream>
#include <vector>
bool isReduce(std::vector<int>& nums){
    bool result = true;
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        result &= nums[i] < nums[i + 1];
        if(!result){
            return false;
        }
    }
    return result;
}
int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums;
    std::vector<int> replacers;
    for (size_t i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        nums.push_back(t);
    }
    for (size_t i = 0; i < k; i++)
    {
        int t;
        std::cin >> t;
        replacers.push_back(t);
    }
    if(k > 2){
        std::cout << "Yes" << std::endl;
    }
    else{
        auto r = std::find(nums.begin(), nums.end(), 0);
        *r = replacers[0];
        if(isReduce(nums)){
            std::cout << "No" << std::endl;
        }
        else{
            std::cout << "Yes" << std::endl;
        }
    }
}