#include <iostream>
inline char encode(char s, char k){
    auto r = -tolower(k) + 'a' + s;
    return islower(s) ? (r < 'a' ? r + 26 : r) : (r < 'A' ? r + 26 : r);
}
int main(){
    std::string input, key;
    std::cin >> key >> input;
    std::string result;
    result.resize(input.length() + 1, '\0');
    int index = 0;
    for (int i = 0; i < input.length(); i++)
    {
        result[i] = encode(input[i], key[index]);
        index = (index + 1) % key.length();
    }
    std::cout << result;
}