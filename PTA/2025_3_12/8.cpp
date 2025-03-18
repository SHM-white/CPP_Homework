#include <iostream>
#include <vector>
#include <string>
using namespace std;

static vector<pair<int,int>> calculateScores(const string &rec, int target) {
    vector<pair<int,int>> results;
    int w = 0, l = 0;
    for (char c : rec) {
        if (c == 'W') w++;
        else if (c == 'L') l++;
        if ((w >= target || l >= target) && (abs(w - l) >= 2)) {
            results.push_back({w, l});
            w = l = 0;
        }
    }
    results.push_back({w, l});
    return results;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    string line, record;
    while (true) {
        if (!getline(cin, line)) break;
        for (char c : line) {
            if (c == 'E') { // 结束标志
                goto process;
            }
            if (c == 'W' || c == 'L') {
                record.push_back(c);
            }
        }
    }
process:
    vector<pair<int,int>> res11 = calculateScores(record, 11);
    for (auto &r : res11) {
        cout << r.first << ":" << r.second << "\n";
    }
    cout << "\n";
    vector<pair<int,int>> res21 = calculateScores(record, 21);
    for (auto &r : res21) {
        cout << r.first << ":" << r.second << "\n";
    }
    return 0;
}
