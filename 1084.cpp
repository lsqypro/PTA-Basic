//
// Created by lsqy on 2020/8/12.
//

/* 1084 外观数列 (20分)
 * 耗时：11:55.24
 *
 * 1. 后面一项是前一项的表述，后一项的内容包括两部分
 *      1. 前一项的字符
 *      2. 前一项的字符的个数
 *      如 n项："aabbccc", n+1项："a2b2c3"
 * 2. calc函数即计算n项的下一项
 *      1. 使用ch标记要统计的字符
 *      2. cnt为要统计的字符个数，当str[i] == ch时cnt++, str[i] != ch时便得到ch的个数cnt
 *      3. 循环结束后判断cnt, 用于统计最后一类字符
 */

#include <iostream>

using namespace std;

string calc(string str) {
    int cnt = 0;
    char ch = str[0];
    string ret;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ch) cnt++;
        else {
            ret += ch;
            ret += cnt+'0';
            cnt = 0;
            ch = str[i];
            i--;
        }
    }
    if (cnt) {
        ret += ch;
        ret += cnt+'0';
    }
    return ret;
}

int main(void) {
    int d, n;
    string ans;

    cin >> ans >> n;
    for (int i = 0; i < n - 1; ++i) {
        ans = calc(ans);
    }
    cout << ans << endl;
    return 0;
}
