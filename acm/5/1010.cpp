#include <iostream>
#include <vector>

#define int long long
using Map = std::vector<std::vector<std::pair<int, int>>>;

void AddEdge(int a, int b, int w, Map& edgeMap){
    edgeMap[a].push_back({b, w % 2});
    edgeMap[b].push_back({a, w % 2});
}
void dfs(int i, Map& map, std::vector<int>& memo, int parity){
    if(memo[i] != -1){
        return;
    }
    memo[i] = parity;
    for (auto& a : map[i]){
        dfs(a.first, map, memo, parity ^ a.second);
    }
}
void solve(){
    int n;
    std::cin >> n;
    Map map(n, std::vector<std::pair<int, int>>{});
    for (size_t i = 0; i < n - 1; i++)
    {
        int a, b, w;
        std::cin >> a >> b >> w;
        AddEdge(a - 1, b - 1, w, map);
    }
    int result[]{0, 0};
    std::vector<int> memo(n, -1);
    dfs(0, map, memo, 0);
    for (auto i : memo){
        if(i != -1){
            result[i]++;
        }
    }
    std::cout << result[0] * result[0] * result[0] + result[1] * result[1] * result[1] << std::endl;
}
signed main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}