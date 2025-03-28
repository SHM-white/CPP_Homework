#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    long long prev2 = 1, prev1 = 1, current;
    for (int i = 2; i <= n; ++i) {
        current = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = current;
    }

    cout << prev1 << endl;
    return 0;
}
