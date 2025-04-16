#include <iostream>
#include <vector>

std::vector<int> cnt(int a, int volume, const std::vector<int>& items) {
    std::vector<std::vector<int>> dp(items.size(), std::vector<int>(volume + 1, 0));
    auto newItems = items;
    newItems.erase(newItems.begin() + (a - 1));
    
    dp[0][0] = 1; // 初始化：容量为0时只有一种方法（不选任何物品）
    for (size_t i = 1; i <= newItems.size(); i++) {
        for (size_t j = 0; j <= volume; j++) {
            dp[i][j] = dp[i - 1][j]; // 不选当前物品
            if (j >= newItems[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - newItems[i - 1]]) % 10; // 选当前物品
            }
        }
    }

    std::vector<int> result(volume + 1, 0);
    for (size_t i = 1; i <= volume; i++) {
        result[i] = dp[newItems.size()][i] % 10;
    }
    return result;
}

int main() {
    int n, v;
    std::cin >> n >> v;
    std::vector<int> items(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> items[i];
    }

    for (size_t i = 1; i <= n; i++) {
        auto result = cnt(i, v, items);
        for (size_t j = 1; j <= v; j++) {
            std::cout << result[j];
        }
        std::cout << std::endl;
    }
}