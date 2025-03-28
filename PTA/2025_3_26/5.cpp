#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::map<std::string, char> levels;
    int n, m;
    std::cin >> n >> m;

    // 读取已知饮料等级
    for (int i = 0; i < n; i++) {
        std::string name;
        char level;
        std::cin >> name >> level;
        levels[name] = level;
    }

    // 处理需要定级的饮料
    for (int i = 0; i < m; i++) {
        std::string name;
        std::cin >> name;

        std::string result = "D"; // 默认等级为 D
        bool found = false;

        // 遍历所有可能的拆分点
        for (size_t j = 1; j < name.length(); j++) {
            std::string part1 = name.substr(0, j);
            std::string part2 = name.substr(j);

            // 检查拆分后的两部分是否都在已知饮料中
            if (levels.count(part1) && levels.count(part2)) {
                if (found) {
                    result = "D"; // 如果有多种拆解方法，定为 D
                    break;
                }
                result = std::string(1, levels[part1]) + levels[part2];
                found = true;
            }
        }

        // 如果名字本身是已知饮料，直接输出等级
        if (levels.count(name)) {
            result = std::string(1, levels[name]);
        }

        std::cout << result << std::endl;
    }
}