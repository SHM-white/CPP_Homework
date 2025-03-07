#include <iostream>
// inline bool isLower(char in){
//     return in >= 'a' && in <= 'z';
// }
inline char decode(int in, int offset){
    offset %= 26;
    if(islower(in)){
        in -= offset;
        while (in > 'z')
        {
            in -= 26;
        }
        while (in < 'a')
        {
            in += 26;
        }
        return in;
    }
    if(isupper(in)){
        in -= offset;
        while (in > 'Z')
        {
            in -= 26;
        }
        while (in < 'A')
        {
            in += 26;
        }
        return in;
    }
    return in;
}
int main(){
    std::string str;
    int offset;
    fscanf(stdin, "%d\n", &offset);
    char input[10240];
    std::cin.getline(input, 10240);
    str = input;
    for(auto i : str){
        std::cout << decode(i, offset);
    }
    std::cout << std::endl;
}