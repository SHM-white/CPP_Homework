#include <iostream>
#include <cstring>
#include <cmath>
class Point{
    public:
        Point() = default;
        Point(float x, float y, const std::string& _name)
        :x{x}, y{y}
        {
            name = new char[_name.length() + 1];
            strcpy(name, _name.c_str());
        }
        Point(const Point& another)
        :x{another.x}, y{another.y}
        {
            std::string a = another.name;
            name = new char[a.length() + 1];
        }
        Point(Point&& another)
        :x{another.x}, y{another.y}, name{another.name}
        {
            another.name = nullptr;
        }
        ~Point(){
            if(name != nullptr){
                delete[] name;
            }
        }
        inline bool operator==(const Point& another) const {
            return x == another.x && y == another.y;
        }
        inline bool operator!=(const Point& another) const {
            return !(*this == another);
        }
        inline bool operator>(const Point& another) const {
            if(x == another.x){
                return y > another.y;
            }
            return x > another.x;
        }
        inline double getDistance(const Point& p){
            return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
        }
        friend inline double getDistance(const Point& p1, const Point& p2){
            return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
        }
        friend inline std::ostream& operator<<(std::ostream& os, const Point& p){
            os << p.name << "(" << p.x << "," << p.y << ")";
            return os;
        }
    private:
        float x{0.0};
        float y{0.0};
        char *name{nullptr};
    };
int main(){
    Point p1{1.1, 2.2, "p1"};
    Point p2{3.2, 1.6, "p2"};
    std::cout << (p1 == p2) << "\n"
              << (p1 != p2) << "\n"
              << (p1 > p2) << "\n"
              << p1 << "\n"
              << p2;
}