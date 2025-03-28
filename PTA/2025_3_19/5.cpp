#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 游戏结构体
struct Game {
    int deadline; // 完成期限
    int penalty;  // 未完成扣款
};

// 比较函数：按扣款金额从大到小排序
bool compare(const Game &a, const Game &b) {
    return a.penalty > b.penalty;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<Game> games(n);
    for (int i = 0; i < n; ++i) {
        cin >> games[i].deadline;
    }
    for (int i = 0; i < n; ++i) {
        cin >> games[i].penalty;
    }

    // 按扣款金额从大到小排序
    sort(games.begin(), games.end(), compare);

    // 用于记录每个时间点是否已被占用
    vector<bool> used(n + 1, false);

    // 贪心选择
    int totalPenalty = 0;
    for (const auto &game : games) {
        // 从游戏的截止时间往前找空闲时间
        for (int t = game.deadline; t > 0; --t) {
            if (!used[t]) {
                used[t] = true; // 占用时间点
                goto next_game; // 完成该游戏，跳到下一个游戏
            }
        }
        // 如果无法在规定时间内完成，累加扣款
        totalPenalty += game.penalty;
    next_game:;
    }

    // 输出剩余资金的理论最大值
    cout << m - totalPenalty << endl;

    return 0;
}
