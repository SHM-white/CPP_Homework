#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <climits>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    
    std::sort(b.begin(), b.end());
    bool greenTurn = true;
    auto getMinDistance = [&](int a, const std::vector<int> &nums)
    {
        int dis = INT_MAX;
        for (auto i : nums){
            dis = std::min(abs(a - i), dis);
        }
        return dis;
    };

    int res = 0;
    for (auto i : a){
        res = std::max(res, getMinDistance(i, b));
    }
    std::cout << res;
    return 0;
}
