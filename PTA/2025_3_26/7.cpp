#include <iostream>
#include <queue>
#include <vector>
using Time = std::pair<long long, long long>;

int main(){
    std::priority_queue<Time, std::vector<Time>, std::greater<Time>> washers{std::greater<Time>()};
    std::priority_queue<Time, std::vector<Time>, std::greater<Time>> dryers{std::greater<Time>()};
    int l, n, m;
    std::cin >> l >> n >> m;
    std::priority_queue<long long> clothes;
    while (n--)
    {
        int t;
        std::cin >> t;
        washers.push({t, t});
    }
    while (m--)
    {
        int t;
        std::cin >> t;
        dryers.push({t, t});
    }
    
    while (l--)
    {
        auto t = washers.top();
        clothes.push(t.first);
        t.first += t.second;
        washers.pop();
        washers.push(t);
    }
    long long finishTime = 0;
    while (clothes.size() > 0)
    {
        auto t = clothes.top();
        clothes.pop();
        auto dryer = dryers.top();
        dryers.pop();
        t += dryer.first;
        dryer.first += dryer.second;
        dryers.push(dryer);
        finishTime = std::max(finishTime, t);
    }
    std::cout << finishTime << std::endl;
}