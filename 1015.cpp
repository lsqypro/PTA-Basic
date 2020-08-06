//
// Created by lsqy on 2020/8/6.
//

/* 1015 德才论 (25分)
 * 耗时：40:01.64
 * 第一类：才德全尽 >= h 此类考生按德才总分从高到低排序
 * 第二类：德胜才 s1 >= h, s2 < h 按总分排序，但排在第一类考生之后
 * 第三类：“才德兼亡”但尚有“德胜才” s1 < h, s2 < h , s1 >= s2 按总分排序，但排在第二类考生之后；
 * 第四类：其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。
 * 当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, h, cnt = 0;  // n:总数，l:>=l考虑录取,h:>=h才德全尽
struct Student {
    int id;
    int s1;
    int s2;
    int get_class() const {
        if (s1 < l || s2 < l) return 5;
        else {
            if (s1 >= h && s2 >=h) return 1;
            else if (s1 >= h && s2 < h) return 2;
            else if (s1 < h && s2 < h && s1 >= s2) return 3;
            else return 4;
        }
    }
    int total() const {
        return s1 + s2;
    }
};

int main(void) {
    vector<Student> stus;
    // 输入
    cin >> n >> l >> h;
    for (int i = 0; i < n; ++i) {
        Student stu;
        cin >> stu.id >> stu.s1 >> stu.s2;
        stus.push_back(stu);
    }
    // 排序
    sort(stus.begin(), stus.end(), [](const Student &s1, const Student &s2){
        int c1 = s1.get_class();
        int c2 = s2.get_class();

        if (c1 < c2) return true; // 按类排序, 低到高
        else if (c1 > c2) return false;
        else {
            // 同类按总成绩排
            if (s1.total() > s2.total()) return true;
            else if (s1.total() < s2.total()) return false;
            else {
                // 当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
                if (s1.s1 > s2.s1) return true;
                else if (s1.s1 < s2.s1) return false;
                else return s1.id < s2.id;
            }
        }
    });

    // 考虑录取学生数
    for_each(stus.begin(), stus.end(), [=](const Student &s){
        if (s.get_class() < 5)
            cnt++;
    });

    // 打印 考虑录取学生
    cout << cnt << endl;
    for_each(stus.begin(), stus.begin() + cnt, [](const Student &s){
        printf("%8d %d %d\n", s.id, s.s1, s.s2);
    });
    return 0;
}