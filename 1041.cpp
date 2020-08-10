//
// Created by lsqy on 2020/8/9.
//

/* 1041 考试座位号 (15分)
 * 耗时：9:50.45
 *
 */

#include <iostream>

using namespace std;

struct Student {
    string id;
    int test_id;
};
Student stus[1000];

int main(void) {
    Student s;
    int n, tid;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        // 准考证号 试机座位号 考试座位号
        cin >> s.id >> tid >> s.test_id;
        stus[tid] = s;
    }
    cin >> n;
    for (int j = 0; j < n; ++j) {
        cin >> tid;
        cout << stus[tid].id << " " << stus[tid].test_id << endl;
    }
    return 0;
}