#include <iostream>
#include <cstring>
#include <cstdio>

class Stmt
{
    unsigned line;
    char *str;
public:
    char *getDetials() const {
        char *result = new char[50];
        sprintf(result, "行号：%d", line);
        return result;
    }
    virtual char *getAsString() const {
        char *result = new char[strlen(str) + 1];
        strcpy(result, str);
        return result;
    }
    void print() const{
        char *s = getAsString();
        std::cout << s << std::endl;
        delete[] s;
    }
    Stmt& setLine(unsigned l){
        this->line = l;
        return *this;
    }
    Stmt& setStr(const std::string& s){
        str = new char[s.length() + 1];
        strcpy(str, s.c_str());
        return *this;
    }
};

int main(){
    Stmt s1, s2;
    s1.setLine(1).setStr("asasa");
    s2.setLine(5).setStr("aaaaaabbbbbb");
    s1.print();
    s2.print();
}