#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <iterator>
#include <compare>
#include <string_view>
#include <cctype>
const int MAPSIZE_H = 100;
const int MAPSIZE_V = 100;
long long memo[MAPSIZE_H][MAPSIZE_V];
class Position{
public:
    Position(int x, int y) : x{x}, y{y} {}
    Position() = default;
    
    Position operator+(const Position& p){
        return Position{x + p.x, y + p.y};
    }
    std::strong_ordering operator<=>(const Position& p) const
    {
        auto r = x <=> p.x;
        if(r == std::strong_ordering::equal){
            return y <=> p.y;
        }
        else{
            return r;
        }
    }
    bool operator==(const Position& p) const
    {
        return (x == p.x && y == p.y);
    }
    int x{0};
    int y{0};
};
std::vector<Position> getControlPoints(Position p){
    std::vector<Position> result;
    result.push_back(p);
    const static std::vector<Position> check{{1, -2}, {-1, -2}, {1, 2}, {-1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
    for(const auto& i:check){
        Position tmp = p + i;
        if((tmp.x >= 0 && tmp.x < MAPSIZE_H) && (tmp.y >= 0 && tmp.y < MAPSIZE_V)){
            result.push_back(tmp);
        }
    }
    return result;
}
long long getCounts(Position current,Position target,const std::vector<Position>& obs){
    if(memo[current.x][current.y] != -1){
        return memo[current.x][current.y];
    }
    if(current.x > target.x || current.y > target.y)
    {
        return 0;
    }
    bool have{false};
    for(auto& p : obs){
        have |= (p == current);
        if(have){
            return 0;
        }
    }
    if(current == target){
        return 1;
    }
    memo[current.x][current.y] = getCounts(Position{current.x + 1, current.y}, target, obs) + getCounts(Position{current.x, current.y + 1}, target, obs);
    return memo[current.x][current.y];
}
int main(){
    for (size_t i = 0; i < MAPSIZE_H; i++)
    {
        for (size_t j = 0; j < MAPSIZE_V; j++)
        {
            memo[i][j] = -1;
        }
        
    }
    
    Position target{};
    Position horse{};
    std::cin >> target.x >> target.y >> horse.x >> horse.y;
    auto obs = getControlPoints(horse);
    std::cout << getCounts(Position{0, 0}, target, obs) << std::endl;
}