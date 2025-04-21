#include <iostream>
#include <vector>
#include <cmath>
bool testNum(long long n){
    //std::vector<bool> nums(n + 1, false);
    long long sum = 0;
    for (size_t i = 1; i <= n / 2; i++)
    {
        if (n % i == 0){
            sum += i;
        }
    }
    return sum == n;
}

int main(){
    const long long CompleteNums[]{6, 28, 496, 8128, 33550336, 8589869056, 137438691328};
    long long m, n;
    std::cin >> m >> n;
    int b{-1};
    int e{0};
    for (int i = 0; i < 8; i++)
    {
        if(m < CompleteNums[i]){
            b = i;
            break;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if(n < CompleteNums[i]){
            e = i;
            break;
        }
    }
    
    std::cout << e - b << std::endl;
}