//
// Created by lsqy on 2020/8/12.
//

/* 1085 PAT单位排行 (25分)
 * 耗时：01:10:43.89
 *
 * 1. 测试点5，两种取整方式答案竟不同
 *      1.  double weight_score = bs / 1.5 + as + ts * 1.5;
 *          int s = int(weight_score);
 *      2.  double weight_score = int(bs / 1.5 + as + ts * 1.5);
 *          int s = weight_score;
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct College{
    string id;
    int cnt, weight_score, bs, as, ts;

    College() {
        cnt = weight_score = bs = as = ts = 0;
    }

    void add(string card, int score) {
        if (card[0] == 'B') bs += score;
        else if (card[0] == 'A') as += score;
        else if (card[0] == 'T') ts += score;
        cnt++;
    }

    void calc() {
        weight_score = bs / 1.5 + as + ts * 1.5;
    }
};

int main(void) {
    int n, score;
    string card, id;
    unordered_map<string, College> cmap;
    vector<College> cv;

    cin >> n;
    for (int i = 0; i < n; ++i) {
//        准考证号 得分 学校
        cin >> card >> score >> id;
        transform(id.begin(), id.end(), id.begin(), ::tolower);
        cmap[id].id = id;
        cmap[id].add(card, score);
    }
    for (auto i : cmap) {
        i.second.calc();
        cv.push_back(i.second);
    }
    sort(cv.begin(), cv.end(), [](const College &c1, const College &c2){
//        学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。
        if (c1.weight_score != c2.weight_score) return c1.weight_score > c2.weight_score;
        else if (c1.cnt != c2.cnt) return c1.cnt < c2.cnt;
        else return c1.id < c2.id;
    });
//    3 pku 100 1
    cout << cv.size() << endl;
    int rank = 1, front_rank = 1;
    int front_score = cv.front().weight_score;
    for (auto i : cv) {
        int weight_score = i.weight_score;
        if (weight_score != front_score) {
            cout << rank << " " << i.id << " " << weight_score << " " << i.cnt << endl;
            front_score = weight_score;
            front_rank = rank;
        }
        else cout << front_rank << " " << i.id << " " << weight_score << " " << i.cnt << endl;
        rank++;
    }
    return 0;
}
