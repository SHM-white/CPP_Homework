#include <iostream>
#include <queue>
#include <vector>
#include <map>
enum Ground
{
    Space = '.',
    Wall = '#',
    Enter = 'E'
};
enum Direction
{
    W = 'W',
    A = 'A',
    S = 'S',
    D = 'D'
};
const Direction DIRECTIONS[]{W, S, A, D};
using Map = std::vector<std::vector<Ground>>;
using Position = std::pair<int, int>;
const std::map<Direction, Position> DELTA_POS{
    {D, {0, 1}},
    {S, {1, 0}},
    {A, {0, -1}},
    {W, {-1, 0}}};
int k;
template<typename T>
inline T& GetItem(std::vector<std::vector<T>>& map, Position p){
    return map[p.first][p.second];
}
template<typename T>
inline const T& GetItem(const std::vector<std::vector<T>>& map, Position p){
    return map[p.first][p.second];
}
template<typename T>
void printMap(const std::vector<std::vector<T>>& map, const std::string& str){
    // std::cout << "---------" << str << "----------" << std::endl;
    // for (const auto& i : map){
    //     for (const auto& j : i){
    //         std::cout << j << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}
void bfs(const Map& map, std::queue<Position>& searchQueue){
    std::vector<std::vector<bool>> searched(map.size(), std::vector<bool>(map[0].size(), false));
    std::vector<std::vector<std::string>> steps(map.size(), std::vector<std::string>(map[0].size(), ""));
    while (!searchQueue.empty()){ 
        Direction stepsBefore;
        Position currentPos = searchQueue.front();
        searchQueue.pop();
        //std::cout << "searching " << currentPos.first << " " << currentPos.second << std::endl;
        if(searched[currentPos.first][currentPos.second]){
            continue;
        }
        auto& currentStep = GetItem(steps, currentPos);
        bool searchAllDirections = currentStep == "";
        searched[currentPos.first][currentPos.second] = true;
        if(!searchAllDirections){
            stepsBefore = (Direction)(*(currentStep.end() - 1));
        }
        for (auto i : DIRECTIONS){
            if(!searchAllDirections){
                if((stepsBefore == W && i == S)
                    || (stepsBefore == S && i == W)
                    || (stepsBefore == A && i == D)
                    || (stepsBefore == D && i == A)
                ){
                    continue;
                }
            }
            Position searchingPos = currentPos;
            while (1)
            {
                auto dpos = DELTA_POS.at(i);
                searchingPos.first += dpos.first;
                searchingPos.second += dpos.second;
                auto t = GetItem(map, searchingPos);
                if (t == Enter)
                {
                    GetItem(steps, searchingPos) = currentStep + (char)i;
                    std::cout << GetItem(steps, searchingPos) << std::endl;
                    return;
                }
                if (t == Wall)
                {
                    searchingPos.first -= dpos.first;
                    searchingPos.second -= dpos.second;
                    if(searched[searchingPos.first][searchingPos.second]){
                        break;
                    }
                    GetItem(steps, searchingPos) = currentStep + (char)i;
                    searchQueue.push(searchingPos);
                    break;
                }
            }
        }
    }
}
int main(){
    int n, m;
    std::cin >> n >> m >> k;
    Map map(n, std::vector<Ground>(m));
    std::queue<Position> searchQueue;
    for (size_t i = 0; i < n; i++)
    {
        getchar();
        for (size_t j = 0; j < m; j++)
        {
            char input;
            input = getchar();
            if(input == 'S'){
                input = '.';
                searchQueue.push({i, j});
            }
            map[i][j] = (Ground)input;
        }
    }
    printMap(map, "MAP");
    bfs(map, searchQueue);
}
