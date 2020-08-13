//
// Created by lsqy on 2020/8/12.
//

/* 1083 是否存在相等的差 (20分)
 * 耗时：11:43.04
 *
 * 1. 相等的差值：差值出现的次数大于1（大于等于2）
 */

#include <iostream>

using namespace std;

int diff_cnt[10001] = {0};

int main(void) {
    int n, value;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        int diff = abs(value-(i+1));
        diff_cnt[diff]++;
    }
    for (int i = 10001-1; i >= 0; --i) {
        if (diff_cnt[i] > 1) cout << i << " " << diff_cnt[i] << endl;
    }
//    按照“差值 重复次数”的格式从大到小输出重复的差值及其重复的次数，每行输出一个结果。
    return 0;
}
