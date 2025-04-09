#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using Map = std::vector<std::vector<int>>;
using Position = std::pair<std::pair<int, int>, int>;
using SearchQueue = std::queue<Position>;

const std::pair<int, int> DELTA_POS[] =
    {
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2},
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1}};

std::vector<Position> GetSearchPos(const Position& p){
    std::vector<Position> pos;
    for (auto i : DELTA_POS){
        pos.push_back({{p.first.first + i.first, p.first.second + i.second}, p.second + 1});
    }
    return pos;
}

auto& GetItem(Map& map, Position& p){
    return map.at(p.first.first).at(p.first.second);
}
bool InMap(const Map& map, const Position& p){
    auto pos = p.first;
    return !(pos.first < 0 || pos.first >= map.size() || pos.second < 0 || pos.second >= map[0].size());
}
void bfs(Map& map, SearchQueue& searchQueue){
    while (!searchQueue.empty())
    {
        auto currentPos = searchQueue.front();
        searchQueue.pop();
        if((!InMap(map, currentPos)) || GetItem(map, currentPos) != -1){
            continue;
        }
        GetItem(map, currentPos) = currentPos.second;
        auto newPos = GetSearchPos(currentPos);
        for (auto& i : newPos){
            searchQueue.push(i);
        }
    }
}
void print(const Map& map){
    for (auto& i : map){
        for (auto& j : i){
            std::cout << std::left << std::setw(5) << j;
        }
        std::cout << std::endl;
    }
}

int main(){
    int m, n, x, y;
    std::cin >> m >> n >> x >> y;
    Map map(m, std::vector<int>(n, -1));
    SearchQueue queue;
    queue.push({{x - 1, y - 1}, 0});
    bfs(map, queue);
    print(map);
}