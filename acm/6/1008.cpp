#include <iostream>
#include <vector>

const long long mod = 1e9l + 7l;

void solve(){
    long long n;
    std::cin >> n;
    long long S = 0;
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        long long a;
        std::cin >> a;
        S = (S + (sum * a)) % mod;
        sum = (a + sum) % mod;
    }

    long long N = 1;
    for (long long i = 2; i <= n; i++){
        N = (N * ((i * (i - 1) / 2) % mod)) % mod;
    }
    std::cout << S << " " << N << std::endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    long long t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}