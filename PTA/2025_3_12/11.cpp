#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long m, n;
    cin >> m >> n;
    vector<long long> perfects = {6, 28, 496, 8128, 33550336};
    int countNum = 0;
    for (auto &p : perfects) {
        if (p >= m && p <= n) {
            countNum++;
        }
    }
    cout << countNum << endl;
    return 0;
}
