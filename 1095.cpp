//
// Created by lsqy on 2020/8/13.
//

/* 1095 解码PAT准考证 (25分)
 * 耗时：01:38:24.54
 *
 * 1. 对于测试点3,4超时优化方案
 *      1. 使用printf代替cout输出
 *      2. 使用unordered_map替代map
 *      3. 对重复的查询条件使用缓存 如使用unordered_map<string, string>保存查询历史
 *      4. 参数传递尽量使用引用或指针
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Card{
    string id;
    int score;

    Card() {score = 0;}
    string get_level() { return id.substr(0, 1);}
    string get_room_id() { return id.substr(1, 3);}
    string get_date() { return id.substr(4, 6);}
    string get_student_id() { return id.substr(10, 3);}
};
vector<Card> cv;

void sort_if(string &arg) {
    vector<Card> tmp;

    for (auto &i : cv) {
        if (i.get_level() == arg) tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end(), [](const Card &c1, const Card &c2){
        if (c1.score != c2.score) return c1.score > c2.score;
        else return c1.id < c2.id;
    });
    for (auto &i : tmp) {
        printf("%s %d\n", i.id.c_str(), i.score);
    }
    if (tmp.empty()) {
        printf("NA\n");
    }
}

void statistics_base_room_id(string &arg) {
    int cnt = 0, total_score = 0;
    for (auto &i : cv) {
        if (i.get_room_id() == arg) cnt++, total_score += i.score;
    }
    if (cnt == 0) {
        printf("NA\n");
    }
    else {
        printf("%d %d\n", cnt, total_score);
    }
}

void statistics_base_date(string &arg) {
    unordered_map<string, int> rmap;

    for (auto &i : cv) {
        if (i.get_date() == arg)
            rmap[i.get_room_id()]++;  // map在这里处理时间较长
    }
    vector<pair<string, int>> rv;
    for (auto &i : rmap) {
        rv.push_back(i);
    }
    sort(rv.begin(), rv.end(), [](pair<string, int> &p1, pair<string, int> &p2){
        if (p1.second != p2.second) return p1.second > p2.second;
        else return p1.first < p2.first;
    });
    for (auto &i : rv) {
        printf("%s %d\n", i.first.c_str(), i.second);
    }
    if (rv.empty()) {
        printf("NA\n");
    }
}

int main(void) {
    int n, m;

    // input
    cin >> n >> m;
    cv.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cv[i].id >> cv[i].score;
    }

    // dispose
    for (int i = 0; i < m; ++i) {
        int opt;
        string arg;
        cin >> opt >> arg;
        printf("Case %d: %d %s\n", i+1, opt, arg.c_str());
        switch (opt) {
            case 1:
                sort_if(arg);
                break;
            case 2:
                statistics_base_room_id(arg);
                break;
            case 3:
                statistics_base_date(arg);
                break;
        }
    }
    return 0;
}
