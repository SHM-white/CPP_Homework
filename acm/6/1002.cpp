#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
void solve(){
    long long n, maxWidth;
    std::cin >> n >> maxWidth;
    std::vector<long long> arr(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        std::cin >> arr[i];
    }
    std::vector<long long> deltas(n + 1);
    for (long long i = 2; i <= n; i++)
    {
        deltas[i] = abs(arr[i] - arr[i - 1]) + deltas[i - 1];
    }
    if(deltas[n] <= maxWidth){
        std::cout << 0 << std::endl;
        return;
    }
    auto isValid = [&](long long length)
    {
        std::deque<long long> items;

        auto addToDeque = [&](long long value) {
            if (!items.empty() && value > items.back()){
                items.pop_back();
            }
            items.push_back(value);
        };

        for (long long i = 1; i < length; i++)
        {
            addToDeque(arr[i]);
        }
        
        for (long long i = length; i <= n; i++)
        {
            auto begin = i - length + 1;
            long long cost = 0;
            addToDeque(arr[i]);
            if(items.front() == arr[begin - 1])
            {
                items.pop_front();
            }
            auto maxInRange = items.front();
            if (begin > 1) {
                cost += deltas[begin - 1];
                cost += abs(maxInRange - arr[begin - 1]);
            }
            if (i < n) {
                cost += deltas[n] - deltas[i + 1];
                cost += abs(maxInRange - arr[i + 1]);
            }
            if(cost <= maxWidth)
            {
                return true;
            }
        }
        return false;
    };
    long long left = 2, right = n;
    while (left < right)
    {
        long long mid = (left + right) / 2;
        if(isValid(mid)) {
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    std::cout << left << std::endl;
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
