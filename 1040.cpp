//
// Created by lsqy on 2020/8/8.
//

/* 1040 有几个PAT (25分)
 * 耗时：30:38.21
 *
 * 1. 第一次遍历统计字符串中'A','T'字符总数于：a_back，t_back
 * 2. 第二次遍历，遍历每个字符时记录该字符前面的'P'个数，以及该字符后的'A'个数
 *    如果当前字符为'P':p_front++
 *    如果当前字符为'A':cnt += p_front * t_back；a_back--;
 *    如果当前字符为'T':t_back--;
 *    当循环条件为：a_back <= 0 || t_back <= 0 时终止循环
 */

#include <iostream>

#define MAX 1000000007
using namespace std;

int main(void) {
    string in_str;
    unsigned long long cnt = 0;
    int p_front = 0, a_back = 0, t_back = 0;

    cin >> in_str;
    // 统计 A T 总个数
    for (int i = 0; i < in_str.length(); ++i) {
        if (in_str[i] == 'A') a_back++;
        else if (in_str[i] == 'T') t_back++;
    }
    // 统计 cnt
    for (int i = 0; i < in_str.length() && a_back > 0 && t_back > 0; ++i) {
        if (in_str[i] == 'P') {
            p_front++;
        }
        else if (in_str[i] == 'A') {
            a_back--;
            cnt += p_front * t_back;
        }
        else {
            t_back--;
        }
    }
    cout << cnt % MAX << endl;
    return 0;
}