#include <iostream>
#include <vector>
#include <algorithm>

//Time-Value
using Items = std::vector<std::pair<int, int>>;
//[count][time]
auto CreateMap(int t, int m){
    return std::vector<std::vector<int>>(m + 1, std::vector<int>(t + 1, 0));
}

int main(){
    int t, m;
    std::cin >> t >> m;
    auto map = CreateMap(t, m);
    Items items;
    for (size_t i = 1; i <= m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        items.push_back({a, b});
        for (int j = 1; j <= t; j++)
        {
            if (j >= a) {
                map[i][j] = std::max(map[i - 1][j], map[i - 1][j - a] + b);
            } else {
                map[i][j] = map[i - 1][j];
            }
        }
    }

    std::cout << map[m][t] << std::endl;
    return 0;
}