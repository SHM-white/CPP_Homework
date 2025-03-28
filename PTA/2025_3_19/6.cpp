#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // 读取果子重量并加入最小堆
    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        minHeap.push(weight);
    }

    int totalCost = 0;

    // 合并果子
    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }

    cout << totalCost << endl;
    return 0;
}
