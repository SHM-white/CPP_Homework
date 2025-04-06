#include <iostream>
#include <vector>

void printNums(int n,std::vector<bool>& printed, int m, std::vector<int>& printedNums){
    if (m == 0){
        for (auto i : printedNums)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (size_t i = 0; i <= n; i++)
    {
        if(i == 0){
            printNums(n, printed, 0, printedNums);
            continue;
        }
        if(!printed[i]){
            printedNums.push_back(i);
            printed[i] = true;
            printNums(n, printed, m - 1, printedNums);
            printed[i] = false;
            printedNums.erase(printedNums.end() - 1);
        }
    }
}
int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<bool> printed;
    std::vector<int> nums;
    printed.resize(n + 1, false);
    printNums(n, printed, m, nums);
}