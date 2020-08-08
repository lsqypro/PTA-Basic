//
// Created by lsqy on 2020/8/8.
//

/* 1038 统计同成绩学生 (20分)
 * 耗时：07:09.47
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int num[101] = {0};
    int n, score, k = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> score;
        num[score] ++ ;
    }

    cin >> k;
    vector<int> s;  // 这里采用vector保存输入的分数，如果同时输入和同时输出的话可能导致测试点3超时
    for (int j = 0; j < k; ++j) {
        cin >> score;
        s.push_back(score);
        // 超时
//        if (j != 0) cout << " ";
//        cout << num[score];
    }

    for (int j = 0; j < k; ++j) {
        if (j != 0) cout << " ";
        cout << num[s[j]];
    }
    cout << endl;
    return 0;
}