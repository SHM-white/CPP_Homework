#include <iostream>
#include <algorithm>
#include <queue>
int main(){
    long long t;
    std::cin >> t;
    while (t--)
    {
        long long k, uses[3];
        std::cin >> k >> uses[0] >> uses[1] >> uses[2];
        long long maxUse = 0;
        long long total = uses[0] + uses[1] + uses[2];
        if(total <= k){
            std::cout << k - total << std::endl;
            continue;
        }
        for (size_t i = 0; i < 3; i++)
        {
            if(uses[i] <= k){
                maxUse = std::max(maxUse, uses[i]);
            }
            if(total - uses[i] <= k){
                maxUse = std::max(maxUse, total - uses[i]);
            }
        }
        std::cout << k - maxUse << std::endl;
    }
}