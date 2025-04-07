#include <iostream>
#include <cstdlib>
#include <cstring>

const int mod = 1e9 + 7;
int f[404][404];
int main(){
    int t;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> t;
    while (t--)
    {
        int n, m, v;
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        std::cin >> n >> m >> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            for (int j = x; j <= v; j++)
            {
                for (int k = m; k >= 1; k--)
                    f[j][k] = (f[j][k] + f[j - x][k - 1]) % mod;
            }
        }
        int ans = 0;
        for (int i = 1; i <= v; i++){
            ans = (ans + f[i][m]) % mod;
        }
        std::cout << ans << std::endl;
    }
}