#include <iostream>
#include <queue>
#include <ranges>
#include <algorithm>
int main(){
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> fruits;
    long long n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        long long t;
        std::cin >> t;
        fruits.push(t);
    }
    long long total = 0;
    while (fruits.size() > 1)
    {
        long long newFruit = fruits.top();
        fruits.pop();
        newFruit += fruits.top();
        fruits.pop();
        total += newFruit;
        fruits.push(newFruit);
    }
    std::cout << total;
}