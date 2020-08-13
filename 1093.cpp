//
// Created by lsqy on 2020/8/13.
//

/* 1093 字符串A+B (20分)
 * 耗时：10:55.91
 *
 * 1. 遍历字符串，判断输出次数是否为0，0输出，非0则跳过
 * 2. 依次输出s1,s2
 */

#include <iostream>

using namespace std;

int ascii_cnt[130] = {0};

int main(void) {
    string s1, s2, ans;

    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.length(); ++i) {
        if (ascii_cnt[s1[i]]++ == 0) ans.push_back(s1[i]);
    }
    for (int i = 0; i < s2.length(); ++i) {
        if (ascii_cnt[s2[i]]++ == 0) ans.push_back(s2[i]);
    }

    cout << ans << endl;
    return 0;
}
