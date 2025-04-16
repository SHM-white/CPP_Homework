#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> stones(N + 1);
    vector<int> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> stones[i];
        prefixSum[i] = prefixSum[i - 1] + stones[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int len = 2; len <= N; ++len) {
        for (int i = 1; i <= N - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefixSum[j] - prefixSum[i - 1]);
            }
        }
    }

    cout << dp[1][N] << endl;
    return 0;
}
