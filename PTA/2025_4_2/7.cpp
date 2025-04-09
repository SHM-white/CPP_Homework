#include <iostream>
#include <vector>
#include <queue>
#include <map>
using Position = std::pair<int, int>;
using Map = std::vector<std::vector<char>>;
using SearchQueue = std::queue<Position>;

const std::pair<int, int> DELTA_POS[]{
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}};
const std::map<char, std::pair<int, int>> MAP_OPERATOR{
    {'<', {0, -1}},
    {'>', {0, 1}}};
std::vector<Position> GetNextPos(const Position& p, const Map& map){
    std::vector<Position> poses;
    for (auto i : DELTA_POS){
        Position newPos = p;
        newPos.first += i.first;
        newPos.second += i.second;
        if(newPos.first >= 0 && newPos.first < map.size() && newPos.second >= 0 && newPos.second < map[0].size()){
            auto a = MAP_OPERATOR.at(map[newPos.first][newPos.second]);
            newPos.first += a.first;
            newPos.second += a.second;
            poses.push_back(newPos);
        }
    }
    return poses;
}
bool bfs(Map& map, SearchQueue& searchQueue, const Position& target){
    std::vector<std::vector<bool>> searched(map.size(), std::vector<bool>(map[0].size(), false));
    while(!searchQueue.empty()){
        auto currentPos = searchQueue.front();
        if(currentPos == target){
            return true;
        }
        searchQueue.pop();
        if(searched[currentPos.first][currentPos.second]){
            continue;
        }
        searched[currentPos.first][currentPos.second] = true;
        auto poses = GetNextPos(currentPos, map);
        for (auto& i : poses){
            searchQueue.push(i);
        }
    }
    return false;
}

int main(){
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        Map map(2, std::vector<char>(n));
        Position target{1, n - 1};
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cin >> map[i][j];
            }
        }
        SearchQueue queue;
        queue.push({0, 0});
        auto r = bfs(map, queue, target);
        std::cout << (r ? "YES" : "NO") << std::endl;
    }
    

}