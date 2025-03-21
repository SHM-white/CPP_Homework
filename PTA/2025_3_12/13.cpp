#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 计算比赛结果
void calculateScores(const string &input, int pointLimit, vector<string> &results) {
    int w = 0, l = 0;
    for (char c : input) {
        if (c == 'W') w++;
        else if (c == 'L') l++;

        // 判断是否结束当前局
        if ((w >= pointLimit || l >= pointLimit) && abs(w - l) >= 2) {
            results.push_back(to_string(w) + ":" + to_string(l));
            w = 0;
            l = 0;
        }
    }
    // 添加最后一局未结束的比分
    results.push_back(to_string(w) + ":" + to_string(l));
}

int main() {
    string input, line;
    // 读取输入
    while (getline(cin, line) && line.find('E') == string::npos) {
        input += line;
    }

    // 11分制结果
    vector<string> results11;
    calculateScores(input, 11, results11);

    // 21分制结果
    vector<string> results21;
    calculateScores(input, 21, results21);

    // 输出11分制结果
    for (const string &score : results11) {
        cout << score << endl;
    }

    // 空行分隔
    cout << endl;

    // 输出21分制结果
    for (const string &score : results21) {
        cout << score << endl;
    }

    return 0;
}
