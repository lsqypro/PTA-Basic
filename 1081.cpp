//
// Created by lsqy on 2020/8/12.
//

/* 1081 检查密码 (15分)
 * 耗时：10:26.85
 *
 * 1. 不少于6个字符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字
 */

#include <iostream>

using namespace std;

string check(string pwd) {
//    该网站要求用户设置的密码必须由不少于6个字符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。
//    如果密码合法，输出Your password is wan mei.；
//    如果密码太短，不论合法与否，都输出Your password is tai duan le.；
//    如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
//    如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
//    如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。
    if (pwd.length() < 6) return "Your password is tai duan le.";
    int digit_cnt = 0, alpha_cnt = 0;
    for (int i = 0; i < pwd.length(); ++i) {
        if (isdigit(pwd[i])) {
            digit_cnt++;
            continue;
        }
        else if (isalpha(pwd[i])) {
            alpha_cnt++;
            continue;
        }
        else if (pwd[i] != '.')
            return "Your password is tai luan le.";
    }
    if (digit_cnt == 0) return "Your password needs shu zi.";
    if (alpha_cnt == 0) return "Your password needs zi mu.";

    return "Your password is wan mei.";
}

int main(void) {
    int n;
    string pwd;

    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        getline(cin, pwd);
        cout << check(pwd) << endl;
    }
    return 0;
}
