#include <iostream>
#include <limits>
using namespace std;

class Cost {
private:
    double meal;     // 每日餐饮开销
    double transport;// 每月交通开销
    double study;    // 年度学习开销

public:
    Cost() : meal(0), transport(0), study(0) {}

    void setMeal(double m) { meal = m; }
    void setTransport(double t) { transport = t; }
    void setStudy(double s) { study = s; }

    double calculateTotal() const {
        return meal * 365 + transport * 12 + study;
    }
};

int main() {
    Cost people[10];

    for (int i = 0; i < 10; i++) {
        cout << "\n=== 第" << i+1 << "位用户 ===" << endl;
        double input;

        while (true) {
            cout << "请输入每日餐饮开销（≥20元）: ";
            if (cin >> input && input >= 20) {
                people[i].setMeal(input);
                break;
            }
            cout << "输入无效！";
            cin.clear();
        }

        while (true) {
            cout << "请输入每月交通开销（≥0元）: ";
            if (cin >> input && input >= 0) {
                people[i].setTransport(input);
                break;
            }
            cout << "输入无效！";
            cin.clear();
        }

        while (true) {
            cout << "请输入年度学习开销（≥0元）: ";
            if (cin >> input && input >= 0) {
                people[i].setStudy(input);
                break;
            }
            cout << "输入无效！";
            cin.clear();
        }
    }

    // 显示年度总开销
    cout << "\n=== 年度总开销汇总 ===" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "用户" << i+1 << ": " << people[i].calculateTotal() << "元" << endl;
    }

    return 0;
}
