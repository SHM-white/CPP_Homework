#include <iostream>

class Energy{
public:
    int energyCount;
    int energyInneed;
    int increaseRate;
    int decreaseRate;
    int dayPass(){
        int tmp = (energyInneed - energyCount) / ((increaseRate - decreaseRate) * 12);
        energyCount += (increaseRate - decreaseRate) * 12 * (tmp - 2);
        return tmp - 2;
    }
    bool timePass(int currentTime){
        if(currentTime > 10 && currentTime <= 22){
            energyCount += increaseRate;
        }
        else{
            energyCount -= decreaseRate;
        }
        return energyCount >= energyInneed;
    }
    bool CanAchieve() const {
        if(increaseRate <= decreaseRate){
            return energyCount + increaseRate * 8 >= energyInneed;
        }
        else return true;
    }
};
std::istream& operator>>(std::istream& is, Energy& energy){
    is >> energy.energyCount >> energy.energyInneed 
        >> energy.increaseRate >> energy.decreaseRate;
    return is;
}
int main(){
    Energy energy;
    std::cin >> energy;
    if(!energy.CanAchieve()){
        std::cout << -1;
        return 0;
    }
    int day = 0;
    //if(energy.energyInneed - energy.energyCount > (energy.increaseRate * 200)){
    //    day += energy.dayPass();
    //}    
    int time = 14;
    while(1){
        (++time) %= 24;
        if(time == 0){
            day++;
        }
        if(energy.timePass(time)){
            std::cout << day;
            break;
        }
    }
}