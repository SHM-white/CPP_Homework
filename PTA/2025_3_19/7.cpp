#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> heights;
    int height;
    while (cin >> height) {
        heights.push_back(height);
    }

    int n = heights.size();
    vector<int> dp(n, 1); // dp[i]表示以heights[i]为结尾的最长非递增子序列长度
    vector<int> systems;  // 存储每个系统的最高拦截高度

    for (int i = 0; i < n; ++i) {
        bool intercepted = false;
        for (int j = 0; j < systems.size(); ++j) {
            if (heights[i] <= systems[j]) {
                systems[j] = heights[i];
                intercepted = true;
                break;
            }
        }
        if (!intercepted) {
            systems.push_back(heights[i]);
        }
    }

    cout << systems.size() << endl;
    return 0;
}
