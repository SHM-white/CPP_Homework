#include <iostream>

template<typename T>
class Cost{
public:
    T meal;
    T transport;
    T study;
    T TotalCost() const {
        return meal * 365 + transport * 12 + study;
    }
    bool input(){
        std::cout << "meal\ttransport\tstudy\n";
        std::cin >> meal >> transport >> study;
        if(meal <= 20){
            meal = transport = study = 0;
            std::cout << "Error: meal is less than 20" << std::endl;
            return false;
        }
        return true;
    }
};

int main(){
    Cost<int> c1;
    while (!c1.input())
        ;
    std::cout << c1.TotalCost();
}