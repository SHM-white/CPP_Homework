#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Project {
    int start, end;
};

// 比较函数，用于按结束时间排序
bool compare(const Project &a, const Project &b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Project> projects(n);

    // 输入项目的开始和结束时间
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end;
    }

    // 按结束时间排序
    sort(projects.begin(), projects.end(), compare);

    int count = 0, last_end = 0;

    // 贪心选择不冲突的项目
    for (const auto &project : projects) {
        if (project.start >= last_end) {
            ++count;
            last_end = project.end;
        }
    }

    cout << count << endl;
    return 0;
}
