#include <iostream>
#include <cstring>

class Course {
private:
    char* name;   
    float credit{0.0}; 

public:
    Course(const char* n, float c)
    :credit{c} 
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    Course(const char *n) : Course{n, 0.0} {}
    Course(float c) : Course{"Null", c} {}
    Course() : Course{"Null", 0.0} {}

    ~Course() {
        delete[] name;
    }

    void displayCourseInfo() {
        std::cout << "课程名: " << name << ", 学分: " << credit << std::endl;
    }
};

int main() {
    // 使用不同构造函数创建课程对象
    Course course1("计算机科学", 3.5);
    Course course2("数学分析");
    Course course3(2.0);
    Course course4;

    // 调用成员函数显示课程信息
    course1.displayCourseInfo();
    course2.displayCourseInfo();
    course3.displayCourseInfo();
    course4.displayCourseInfo();

    return 0;
}
