#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<bool> isPrime(n+1, true);
    isPrime[0] = false; 
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++){
        if (isPrime[i]){
            for (int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    primes.reserve(n / 10); // 预分配空间
    for (int i = 2; i <= n; i++){
        if (isPrime[i]) primes.push_back(i);
    }

    while (q--){
        int k; 
        cin >> k;
        cout << primes[k-1] << "\n";
    }
    return 0;
}
