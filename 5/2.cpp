#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <memory>
class Stmt
{
protected:
    unsigned line;
    char *str{nullptr};

public:
    Stmt() = default;
    Stmt(unsigned line, const std::string& str)
    :line{ line }{
        setStr(str);
    }
    ~Stmt(){
        if(str != nullptr){
            delete[] str;
        }
    }
    virtual char *getDetials() const {
        char *result = new char[50];
        sprintf(result, "行号：%d\n", line);
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

class BinaryOperator : public Stmt
{
protected:
    char *str2{nullptr};
    char op[10];
    char type[10];
public:
    BinaryOperator(unsigned line, const std::string& str1, const std::string& _op, const std::string& _str2, const std::string& _type)
    :Stmt{line, str1}{
        strcpy(op, _op.c_str());
        str2 = new char[_str2.length() + 1];
        strcpy(str2, _str2.c_str());
        strcpy(type, _type.c_str());
    }
    ~BinaryOperator(){
        if(str2 != nullptr){
            delete[] str2;
        }
    }
    char *getDetials() const override{
        char *result = new char[50];
        sprintf(result, "行号：%d, 类型：%s\n", line, type);
        return result;
    }
    char *getAsString() const override{
        char *result = new char[strlen(str) + strlen(str2) + strlen(op) + 3];
        sprintf(result, "%s %s %s", str, op, str2);
        return result;
    }
    
};
void printDetails(Stmt* line){
    auto i = line->getDetials();
    std::cout << i << std::endl;
    delete[] i;
}
int main(){
    std::vector<std::unique_ptr<Stmt>> lines;
    lines.push_back(std::make_unique<Stmt>(1, "asdfghj"));
    lines.push_back(std::make_unique<BinaryOperator>(2, "asasgdf", "==", "aaaaaa", "bool"));

    for (auto& i : lines){
        i->print();
        printDetails(i.get());
    }
}