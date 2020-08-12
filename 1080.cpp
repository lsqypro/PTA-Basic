//
// Created by lsqy on 2020/8/12.
//

/* 1080 MOOC期终成绩 (25分)
 * 耗时：34:14.416
 *
 * 1. 输入3类数据保存到map<string, Student> smap中
 * 2. 遍历smap,计算是否合格，将合格学生加入vector<Student> sv
 * 3. 根据总评成绩和学号字典序对sv排序
 * 4. 遍历输出sv
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    int p_s, m_s, f_s, t_s;
    int qualified;

    Student() {
        p_s = m_s = f_s = -1;
        qualified = 0;
    }

    void calc() {
        if (m_s > f_s) {
            t_s = m_s * 0.4 + f_s * 0.6 + 0.5;
        }
        else t_s = f_s;
//        不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）
        if (p_s >= 200 && t_s >= 60) qualified = 1;
    }

    void print() {
        cout << name << " " << p_s << " " << m_s << " " << f_s << " " << t_s << endl;
    }
};

int main(void) {
    int p, m, n, score;
    string name;
    map<string, Student> smap;
    vector<Student> sv;

    // input
    cin >> p >> m >> n;
    for (int i = 0; i < p; ++i) {
        cin >> name >> score;
        smap[name].p_s = score;
        smap[name].name = name;
    }
    for (int i = 0; i < m; ++i) {
        cin >> name >> score;
        smap[name].m_s = score;
        smap[name].name = name;
    }
    for (int i = 0; i < n; ++i) {
        cin >> name >> score;
        smap[name].f_s = score;
        smap[name].name = name;
    }

    // calc
    for (auto it : smap) {
        it.second.calc();
        if (it.second.qualified == 1) sv.push_back(it.second);
    }

    // sort
    sort(sv.begin(), sv.end(), [](const Student &s1, const Student &s2){
        if (s1.t_s != s2.t_s) return s1.t_s > s2.t_s;
        else return s1.name < s2.name;
    });

    // output
    for (auto i : sv) {
        i.print();
    }
    return 0;
}
