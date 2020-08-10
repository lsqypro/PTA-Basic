//
// Created by lsqy on 2020/8/9.
//

/* 1047 编程团体赛 (20分)
 * 耗时：10:30.66
 *
 * 格式为：队伍编号-队员编号 成绩，其中队伍编号为 1 到 1000 的正整数，队员编号为 1 到 10 的正整数，成绩为 0 到 100 的整数。
 */

#include <iostream>
#include <vector>

using namespace std;

int teams[1001] = {0};

int main(void) {
    int n, tid, sid, score;
    int max_id, max_score = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        // 队伍编号-队员编号 成绩
        scanf(" %d-%d %d", &tid, &sid, &score);
        teams[tid] += score;
        if (teams[tid] > max_score) {
            max_score = teams[tid];
            max_id = tid;
        }
    }
    cout << max_id << " " << max_score << endl;
    return 0;
}