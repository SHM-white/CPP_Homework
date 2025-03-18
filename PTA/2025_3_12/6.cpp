#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
int main(){
    std::map<int, int, std::greater<int>> contributions;
    long total, displayCount, questionCount;
    std::cin >> total >> displayCount >> questionCount;
    for (long i = 0; i < total; i++)
    {
        std::cin >> contributions[i];
    }
    std::vector<int> displaying;
    for (long i = 0; i < questionCount; i++)
    {
        int op, id;
        std::cin >> op >> id;
        switch (op)
        {
        case 1:
            if(displaying.size() < displayCount){
                displaying.push_back(id);
            }
            else{
                auto minID = std::min_element(displaying.begin(), displaying.end(), [&](int a, int b)
                                              { return contributions[a - 1] < contributions[b - 1]; });
                if (contributions[(*minID) - 1] < contributions[id - 1])
                {
                    (*minID) = id;
                }
            }
            break;
        case 2:
            {            
                bool result = false;
                for (auto i : displaying){
                    result |= (i == id);
                }
                std::cout << (result ? "YES" : "NO") << std::endl;
            }            
            break;
        default:
            break;
        }
    }
    return 0;
}