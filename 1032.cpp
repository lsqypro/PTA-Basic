//
// Created by lsqy on 2020/8/8.
//

/* 1032 挖掘机技术哪家强 (20分)
 * 耗时：5:21.07
 */

#include <iostream>

using namespace std;

int main(void) {
//    给出总得分最高的学校的编号、及其总分，中间以空格分隔
    int score[100001] = {0};
    int n, id, s, max_id, max_s = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id >> s;
        score[id] += s;
        if (score[id] > max_s) {
            max_s = score[id];
            max_id = id;
        }
    }
    cout << max_id << " " << max_s << endl;
    return 0;
}