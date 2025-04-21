#include <iostream>
#include <queue>

using WaitQueue = std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long,long long>>, std::greater<std::pair<long long,long long>>>;

int main(){
    long long l, m, n;
    std::cin >> l >> n >> m;
    WaitQueue washers;
    WaitQueue dryers;
    for (size_t i = 0; i < n; i++)
    {
        long long t;
        std::cin >> t;
        washers.push({t, t});
    }
    for (size_t i = 0; i < m; i++)
    {
        long long t;
        std::cin >> t;
        dryers.push({t, t});
    }
    std::priority_queue<long long> washed;
    while (l--)
    {
        auto w = washers.top();
        washers.pop();
        washers.push({w.first + w.second, w.second});
        washed.push(w.first);
    }
    long long result = 0;
    while (!washed.empty())
    {
        auto c = washed.top();
        washed.pop();
        auto d = dryers.top();
        dryers.pop();
        dryers.push({d.first + d.second, d.second});
        result = std::max(result, c + d.first);
    }
    std::cout << result << std::endl;
}