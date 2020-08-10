//
// Created by lsqy on 2020/8/9.
//

/* 1043 输出PATest (20分)
 * 耗时：18:34.03
 *
 * redlesPayBestPATTopTeePHPereatitAPPT
 * PATestPATestPTetPTePePee
 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str, ans;
    int p = 0, a = 0, t = 0, e_ = 0, s_ = 0, t_ = 0, cnt = 0;
    cin >> str;

    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (ch == 'P') p++, cnt++;
        else if (ch == 'A') a++, cnt++;
        else if (ch == 'T') t++, cnt++;
        else if (ch == 'e') e_++, cnt++;
        else if (ch == 's') s_++, cnt++;
        else if (ch == 't') t_++, cnt++;
    }

    for (int i = 0; i < cnt; ) {
        if (p > 0) {
            ans.push_back('P');
            p--, i++;
        }
        if (a > 0) {
            ans.push_back('A');
            a--, i++;
        }
        if (t > 0) {
            ans.push_back('T');
            t--, i++;
        }
        if (e_ > 0) {
            ans.push_back('e');
            e_--, i++;
        }
        if (s_ > 0) {
            ans.push_back('s');
            s_--, i++;
        }
        if (t_ > 0) {
            ans.push_back('t');
            t_--, i++;
        }
    }
    cout << ans << endl;
    return 0;
}