#include <iostream>
#include <vector>
#include <climits>
auto CreateMap(int n){
    std::vector<int> map(n + 1, INT_MAX / 2);
    map[0] = 0;
    map[1] = 1;
    map[5] = 1;
    map[11] = 1;
    return map;
}
int dfs(int n, std::vector<int>& map){
    for (int i = 0; i <= n; i++)
    {
        for (auto j : {1, 5, 11}){
            if((i - j) >= 0){
                map[i] = std::min(map[i], map[i - j] + 1);
            }
        }
    }
    return map[n];
}
int main(){
    int n;
    std::cin >> n;
    auto map = CreateMap(n);
    auto result = dfs(n, map);
    std::cout << result << std::endl;
}