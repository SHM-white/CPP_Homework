#include <iostream>
int main(){
    long long n;
    std::cin >> n;
    while (n > 0)
    {
        std::cout << n % 10 << " ";
        n /= 10;
    }
}