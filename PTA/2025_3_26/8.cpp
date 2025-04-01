#include <iostream>
#include <string>
#include <vector>

int main(){
    int n, k;
    std::cin >> n;
    std::vector<std::string> replaceStrs;
    while (n--)
    {
        std::string t;
        std::cin >> t;
        replaceStrs.push_back(t);
    }
    std::cin >> k;
    std::cin.ignore();
    int count = 0;
    std::string line;
    const std::string replaceTarget0{"<->"};
    const std::string replaceTarget{"<censored>"};
    std::getline(std::cin, line);
    for (auto i : replaceStrs){
        size_t r;
        while ((r = line.find(i)) != line.npos)
        {
            line.erase(r, i.length());
            line.insert(r, replaceTarget0);
            count++;
        }
    }
    if(count >= k){
        std::cout << count << '\n'
                  << "He Xie Ni Quan Jia!" << std::endl;
    }
    else{
        size_t r;
        while ((r = line.find(replaceTarget0)) != line.npos)
        {
            line.erase(r, 3);
            line.insert(r, replaceTarget);
        }
        std::cout << line;
    }
}