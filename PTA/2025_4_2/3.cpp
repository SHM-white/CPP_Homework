#include <iostream>
#include <vector>

bool TestCase(const std::vector<int>& map, int size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (map[i] == map[j] || abs((int)i - (int)j) == abs(map[i] - map[j])) {
                return false; // 提前返回，减少不必要的计算
            }
        }
    }
    return true;
}

void update(std::vector<int>& map, std::vector<std::vector<int>>& results, int index) {
    if (index >= map.size()) {
        results.push_back(map); // 直接保存结果，避免重复检查
        return;
    }
    for (size_t i = 0; i < map.size(); i++) {
        map[index] = i; // 设置当前行的值
        if (TestCase(map, index + 1)) { // 仅在当前部分有效时继续递归
            update(map, results, index + 1);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> map(n, 0); // 初始化为0
    std::vector<std::vector<int>> results;
    update(map, results, 0);
    int count = 0;
    for (const auto& i : results) {
        if(count >= 100){
            break;
        }
        for (const auto& b : i) {
            std::cout << b + 1 << " "; // 输出从1开始的结果
        }
        std::cout << std::endl;
        count++;
    }
    std::cout << results.size();
}