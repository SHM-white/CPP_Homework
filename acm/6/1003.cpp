#include <iostream>
#include <vector>

using Map = std::vector<std::pair<long long, long long>>;

std::vector<long long> treeList;

void add(long long p, long long delta_value){
    for (long long i = p; i < treeList.size(); i += i & -i){
        treeList[i] += delta_value;
    }
}

long long get(long long p){
    long long result = 0;
    for (long long i = p; i > 0; i -= i & -i){
        result += treeList[i];
    }
    return result;
}
inline long long getTotal(const std::pair<long long, long long>& p){
    return p.first + p.second;
}
void solve(){
    long long n;
    std::cin >> n;
    treeList.clear();
    treeList.resize(n + 1, 0);
    Map map(n + 1, {0, 0});
    for (size_t i = 1; i <= n; i++)
    {
        std::cin >> map[i].first;
        add(i, map[i].first);
    }
    for (size_t i = 1; i <= n; i++)
    {
        std::cin >> map[i].second;
    }
    long long l = 1;
    long long lastValue = getTotal(map[1]);
    long long result = 0;
    for (long long r = 1; r <= n; r++)
    {
        if(lastValue != getTotal(map[r])){
            result = std::max(result, (get(r - 1) - get(l - 1)) * (r - l));
            l = r;
            lastValue = getTotal(map[r]);
        }
    }
    result = std::max(result, (get(n) - get(l - 1)) * (n - l + 1));
    std::cout << result << std::endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}