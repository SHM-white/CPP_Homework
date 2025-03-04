#include <iostream>
char *remove(char *str, char *chars){
    auto strLen = std::string(str).length();
    char *newStr = new char[strLen + 1];
    int index_new = 0;
    int index = 0;
    while (index < strLen)
    {
        bool needDel = false;
        for(auto c : std::string(chars)){
            needDel |= c == str[index];
        }
        if(!needDel){
            newStr[index_new] = str[index];
            index_new++;
        }
        index++;
    }
    newStr[index_new] = '\0';
    return newStr;
}
int main(){
    std::string str, chars;
    std::cin >> str >> chars;
    char *newStr = remove(str.data(), chars.data());
    std::cout << newStr << std::endl;
}