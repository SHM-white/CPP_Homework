#include <iostream>
using namespace std;

int main() {
    long long m;
    cin >> m;

    // 优先使用5，再使用2，最后使用1
    long long count = m / 5; // 使用5的次数
    m %= 5;
    count += m / 2;         // 使用2的次数
    m %= 2;
    count += m;             // 使用1的次数

    cout << count << endl;
    return 0;
}
