#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i=1; i<n; i++){
        // i从1开始计数需注意，下标i对应的是第i+1个元素
        if(((i+1) % 2 == 0 && a[i] < a[i-1]) ||
           ((i+1) % 2 == 1 && a[i] > a[i-1])){
            swap(a[i], a[i-1]);
        }
    }
    // 输出结果
    for(int i=0; i<n; i++){
        cout << a[i] << (i<n-1 ? ' ' : '\n');
    }
    return 0;
}
