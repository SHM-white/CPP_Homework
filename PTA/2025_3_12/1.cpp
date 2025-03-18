#include <iostream>
long long getMinDivider(long long a, long long b){
    if(a < b){
        std::swap(a, b);
    }
    long long c = a % b;
    while (c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
int main(){
    long long a, b;
    std::cin >> a >> b;
    auto c = getMinDivider(a, b);
    std::cout << c << " " << a * b / c;
}