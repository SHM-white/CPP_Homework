#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>

// 存储图的结构：邻接表，每个元素是 (相邻节点编号, 权重)
std::vector<std::vector<std::pair<int, int>>> graph;
// 每个节点记录其访问过的邻居节点集合
std::vector<std::unordered_set<int>> vis;
// 记忆化数组
std::vector<int> memo;

// DFS函数寻找从当前节点到目标节点的最大分数
int dfs(int curr, int target) {
    // 如果已到达目标
    if (curr == target) return 0;
    
    // 如果已计算过
    if (memo[curr] != INT_MIN / 2) return memo[curr];
    
    int maxScore = INT_MIN / 2;
    
    // 遍历当前节点的所有边
    for (auto& [next, score] : graph[curr]) {
        // 如果该边未被访问
        if (vis[curr].find(next) == vis[curr].end()) {
            // 标记边为已访问
            vis[curr].insert(next);
            
            // 递归计算从下一节点到目标的最大分数
            int nextScore = dfs(next, target);
            
            // 如果存在路径到目标
            if (nextScore != INT_MIN / 2) {
                maxScore = std::max(maxScore, nextScore + score);
            }
            
            // 回溯，标记边为未访问
            vis[curr].erase(next);
        }
    }
    
    // 保存并返回结果
    return memo[curr] = maxScore;
}

void solve() {
    int n;
    std::cin >> n;
    
    // 初始化数据结构
    graph.assign(n + 1, std::vector<std::pair<int, int>>());
    vis.assign(n + 1, std::unordered_set<int>());
    memo.assign(n + 1, INT_MIN / 2);
    
    // 读取边信息
    for (int i = 0; i < n - 1; i++) {
        int u, v, p, q;
        std::cin >> u >> v >> p >> q;
        
        // 添加双向边
        graph[u].push_back({v, p});
        graph[v].push_back({u, q});
    }
    
    int start, end;
    std::cin >> start >> end;
    
    // 计算并输出结果
    int result = dfs(start, end);
    std::cout << result << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}