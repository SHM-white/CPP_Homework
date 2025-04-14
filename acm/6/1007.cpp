#include <iostream>
#include <vector>
#include <queue>
#include <string>
using Map = std::vector<std::pair<char, long long>>;

void solve(){
    long long n;
    std::cin >> n;
    std::vector<long long> map(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }

    std::priority_queue<long long> redBlocks;
    std::priority_queue<long long> blackBlocks;

    std::cin.ignore();
    for (size_t i = 0; i < n; i++)
    {
        char c;
        std::cin >> c;
        (c == 'R') ? (redBlocks.push(map[i])) : (blackBlocks.push(map[i]));
    }
    long long sum = 0;
    while (!redBlocks.empty())
    {
        sum += redBlocks.top();
        redBlocks.pop();
        if (!blackBlocks.empty()){
            sum += blackBlocks.top();
            blackBlocks.pop();
        }
        else{
            break;
        }
    }
    
    std::cout << sum << std::endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    long long t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}