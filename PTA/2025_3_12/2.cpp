#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
class Scores{
public:
    int id;
    int point_2;
    int point_4;
    int point_8;
    int total_score;
    Scores(int id, int a, int b, int c) 
    : id{id}, point_2{a}, point_4{b}, point_8{c} {
        total_score = point_2 + point_4 + point_8;
    };
    bool operator>(const Scores& another) const {
        if(total_score == another.total_score){
            if(point_2 == another.point_2){
                return id < another.id;
            }
            else{
                return point_2 > another.point_2;
            }
        }
        else{
            return total_score > another.total_score;
        }
    }
};
std::ostream& operator<<(std::ostream& os, const Scores& scores){
    os << scores.id << " " << scores.total_score << std::endl;
    return os;
}
int main(){
    std::vector<Scores> persons;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        persons.push_back(Scores{i + 1, a, b, c});
    }
    std::sort(persons.begin(), persons.end(), [](const Scores &a, const Scores &b)
              { return a > b; });
    for (int i = 0; i < std::min(5, (int)persons.size()); i++)
    {
        std::cout << persons[i];
    }
}