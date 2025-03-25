#include <iostream>
#include <cstring>
class Date{
public:
    Date(int year, int month, int day) : year{year}, month{month}, day{day} {}
    Date() = default;
    Date(const Date& a) = default;
    Date(Date &&a) = default;
    Date &operator=(const Date &a) = default;
    int year{0};
    int month{0};
    int day{0};
};
std::ostream& operator<<(std::ostream& os, const Date& d){
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}
class Person{
public:
    Person(){
        name = new char[1];
        name[0] = '\0';
        _count++;
    }
    Person(const std::string& _name, char gender, const Date& birthday, int cashFlow = 0)
    :gender{gender}, birthday{birthday}, cashFlow{cashFlow}
    {
        name = new char[_name.length() + 1];
        strcpy(name, _name.c_str());
        _count++;
    }
    Person(const Person& another)
    :gender{another.gender}, birthday{another.birthday}, cashFlow{another.cashFlow}
    {
        name = new char[strlen(another.name) + 1];
        strcpy(name, another.name);
        _count++;
    }
    ~Person(){
        delete[] name;
        _count--;
    }

    void print() const {
        std::cout << (*this);
    }
    inline int getCashFlow() const {
        return cashFlow;
    }

    static inline int getCount(){
        return _count;
    }
    friend inline std::ostream& operator<<(std::ostream& os, const Person& p){
        os << "姓名：" << p.name << "， 性别：" << (p.gender == 'f' ? "女" : "男") << "， 生日：" << p.birthday << ";" << std::endl;
        return os;
    }
private:
    char *name;
    char gender{'m'};
    Date birthday{1970, 1, 1};
    int cashFlow{0};
    static inline int _count{0};
};
int main()
{
    Person p1, p2("zhang", 'f', Date(1991, 1, 1)), p3(p2);
    p3.print(); // 输出: 姓名:zhang; 性别:女; 生日:1991−1−1;
    std::cout << "收支为：" << p3.getCashFlow() << "元" << std::endl; // 输出：0元
    Person *p = new Person("li", 'm', Date(1990, 2, 2), 800);
    p->print(); // 输出: 姓名:li ; 性别:男; 生日:1990−2−2;
    std::cout << "收支为：" << p->getCashFlow() << "元" << std::endl; // 输出：800元
    std::cout << "总人数：" << p1.getCount() << std::endl; // 输出：4
    delete p;
    std::cout << "总人数：" << p1.getCount() << std::endl; // 输出：3
    return 0;
}