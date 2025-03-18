#include <iostream>
#include <vector>
using namespace std;

static string multiplyLarge(const string &a, const string &b) {
    if (a == "0" || b == "0") return "0";
    vector<int> res(a.size() + b.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
            int tmp = (a[i] - '0') * (b[j] - '0') + res[i + j + 1];
            res[i + j + 1] = tmp % 10;
            res[i + j] += tmp / 10;
        }
    }
    string product;
    for (int r : res) {
        if (!(product.empty() && r == 0)) product.push_back(r + '0');
    }
    return product.empty() ? "0" : product;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << multiplyLarge(a, b) << endl;
    return 0;
}
