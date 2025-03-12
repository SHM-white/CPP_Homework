#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int main(){
    int totalCount = 0, maxCount, minCount, count = 0;
    bool isFirst = true;
    std::string line;
    line.resize(1000000);
    std::cin.getline(line.data(), 1000000);
    std::stringstream strStream{std::string{line.c_str()}};
    while (!strStream.eof())
    {
        int t;
        strStream >> t;
        if(isFirst){
            maxCount = minCount = t;
            isFirst = false;
        }
        else{
            maxCount = std::max(t, maxCount);
            minCount = std::min(t, minCount);
        }
        totalCount += t;
        count++;
    }
    printf("%d %d %.3f", minCount, maxCount, totalCount/(double)count);
}