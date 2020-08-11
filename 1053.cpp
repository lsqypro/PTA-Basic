//
// Created by lsqy on 2020/8/10.
//

/* 1053 住房空置率 (20分)
 * 耗时：12:31.70
 *
 */

#include <iostream>

using namespace std;

int main(void) {
    double e, value;
    int n, d, days;
    int sum1 = 0, sum2 = 0, cnt = 0;

//    在观察期内，若存在超过一半的日子用电量低于某给定的阈值 e，则该住房为“可能空置”；
//    若观察期超过某给定阈值 D 天，且满足上一个条件，则该住房为“空置”。
    cin >> n >> e >> d;
    for (int i = 0; i < n; ++i) {
        cin >> days;
        cnt = 0;
        for (int j = 0; j < days; ++j) {
            cin >> value;
            if (value < e) cnt++;
        }
        if (cnt > days/2) {
            if (days > d) sum2++;
            else sum1++;
        }
    }

//    在一行中输出“可能空置”的比率和“空置”比率的百分比值，其间以一个空格分隔，保留小数点后 1 位。
    printf("%0.1f%% %0.1f%%\n", double(sum1)/n*100, double(sum2)/n*100);
    return 0;
}