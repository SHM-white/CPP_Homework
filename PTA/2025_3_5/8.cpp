#include <iostream>
int main(){
    long long n;
    long long newNum = 0;
    std::cin >> n;
    while (n > 0)
    {
        newNum *= 10;
        newNum += n % 10;
        n /= 10;
    }
    std::cout << newNum << std::endl;
}