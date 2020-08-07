//
// Created by lsqy on 2020/8/7.
//

/* 1030 完美数列 (25分)
 * 耗时：38:56.81
 *
 * 1. 求组成完美数列中元素最多个数
 * 2. 固定i, j从i+cnt处判断（i+cnt-i+1 = cnt + 1)，测试点4关键
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, cnt = 0;
    unsigned long long num, p;  // p<=10^9, num<=10^9 num*p <= 10^18选用long long
    vector<unsigned long long> nums;

    // input
    cin >> n >> p;  // 第一行给出两个正整数 N 和 p
    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
    }

    /* 1. 由低到高排序
     * 2. 固定m,M从小到大判断
     * 3. 第一个循环：cnt >= nums.size()-i时没有必要继续计算
     * 4. 第二个循环：cnt >= j - i + 1时没有必要继续计算
     * 5. 固定i,j从i+cnt处判断（i+cnt-i+1 = cnt + 1)，测试点4关键
     */
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() && cnt < nums.size()-i; ++i) {
        for (int j = i + cnt; j < nums.size(); j++) {
            if (nums[j] > nums[i] * p) break;  // nums[i] * p固定，nums[j]递增
            if (j - i + 1 > cnt) cnt = j - i + 1;
        }
    }

    // output
    cout << cnt << endl;

    return 0;
}