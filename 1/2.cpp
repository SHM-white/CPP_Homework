#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <memory>

class Student
{
public:
    std::string name;
    int score;
};
static inline std::istream& operator>>(std::istream& istream, Student& student){
    istream >> student.name >> student.score;
    return istream;
}

//print students score under 60

void GetUnpassedStudents(std::vector<std::shared_ptr<Student>>& students){
    std::vector<std::shared_ptr<Student>> results;
    for(auto& i: students){
        if(i->score < 60){
            results.push_back(i);
        }
    }
    std::cout << "Students under 60 count: " << results.size() << std::endl;
    for (auto& i : results)
    {
        std::cout << "Name:" << i->name << " Score:" << i->score << std::endl;
    }
}
//print students over avarage
void GetStudentsOverAvarage(std::vector<std::shared_ptr<Student>>& students){
    int total = 0;
    for(auto& i : students){
        total += i->score;
    }
    double avarage = ((double)total) / students.size();
    int count = 0;
    std::cout << "Students over avarage:\n";
    for (auto &i : students | std::ranges::views::filter([&](std::shared_ptr<Student> &i)
                                                         { return i->score > avarage; }))
    {
        std::cout << i->name << std::endl;
        count++;
    }
    std::cout << "Total: " << count << std::endl;
}
//seperate students
void seperateStudents(std::vector<std::shared_ptr<Student>>& students){
    auto studentsCopy = students;
    std::sort(studentsCopy.begin(), studentsCopy.end());
    std::vector<std::pair<int, int>> seperators = {{0, 59}, {60, 69}, {70, 79}, {80, 89}, {90, 99}, {100, 100}};
    for(auto i : seperators){
        std::cout << "[" << i.first << "~" << i.second << "]:";
        int count = 0;
        for (auto &a : students | std::ranges::views::filter([&](std::shared_ptr<Student> &s)
                                                             { return s->score >= i.first && s->score <= i.second; }))
        {
            count++;
        }
        std::cout << count << std::endl;
    }
}
int main(){
    std::vector<std::shared_ptr<Student>> students;
    while (1)
    {
        auto student = std::make_shared<Student>();
        std::cin >> (*student);
        if(student->score < 0){
            break;
        }
        students.push_back(student);
    }
    GetUnpassedStudents(students);
    GetStudentsOverAvarage(students);
    seperateStudents(students);
}