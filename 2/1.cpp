#include <iostream>
#include <regex>
#include <fstream>
int main(){
    std::string filePath;
    std::cin >> filePath;
    std::ifstream inputFile{filePath, std::ios::in};
    if(!inputFile.is_open()){
        return -1;
    }
    int lineCount = 0;
    while (!inputFile.eof())
    {
        std::string tmp;
        char buf[10240];
        inputFile.getline(buf, 10240);
        tmp = buf;
        std::regex target {"(\\w+)"};
        auto words_begin = std::sregex_iterator(tmp.begin(), tmp.end(), target);
        auto words_end = std::sregex_iterator();
        std::cout << tmp << ": " << std::distance(words_begin, words_end) << std::endl;
        lineCount++;
        if(lineCount >= 24){
            system("pause");
            lineCount = 0;
        }
    }
    return 0;
}