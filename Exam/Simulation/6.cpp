#include <iostream>
#include <vector>

using Map = std::vector<int>;
int totalPrint = 0;
bool Check(const Map& map, int index){
    if(index == 0){
        return 1;
    }
    for (int i = 0; i <= index; i++)
    {
        for (int j = i + 1; j <= index; j++)
        {
            if(abs(map[i] - map[j]) == abs(j - i)){
                return false;
            }
            if(map[i] == map[j]){
                return false;
            }
        }
    }
    return true;
    
}
void printMap(const Map& map){
    for (const auto& i : map){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void dfs(Map& map, int index){
    if(index >= map.size()){
        return;
    }
    for (size_t i = 1; i <= map.size(); i++)
    {
        map[index] = i;
        if(Check(map, index)){
            if(index == map.size() - 1){
                if(totalPrint < 100){
                    printMap(map);
                }
                totalPrint++;
            }
            else{
                dfs(map, index + 1);
            }
        }
    }
}
int main(){
    int n;
    std::cin >> n;
    Map map(n, 1);
    dfs(map, 0);
    std::cout << totalPrint << std::endl;
}