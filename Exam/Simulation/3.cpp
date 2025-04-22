#include <iostream>
#include <vector>
#include <algorithm>
int getMinDistance(const std::vector<int>& s, int n){
    int result = abs(s[0] - n);
    for (auto i : s){
        result = std::min(abs(i - n), result);
    }
    return result;
}
int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    int result = 0;
    std::sort(a.begin(), a.end());
    for (auto i : a){
        result = std::max(result, getMinDistance(b, i));
    }
    std::cout << result << std::endl;
    
}