//
// Created by lsqy on 2020/8/9.
//

/* 1044 火星数字 (20分)
 * 耗时：01:49:46.50
 *
 * 1. 只有两位，即数字范围 0-12*13+12 [0,168]
 * 2. 高位存在且低位为0时，只写高位 （如13对应tam 而不是tam tret）
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

string low_map[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string hig_map[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string parse(int digit) {
    string ans;
    int h = digit / 13, l = digit % 13;

    if (h) {
        ans = hig_map[h];
        if (l) ans += " " + low_map[l];
    }
    else ans = low_map[l];

    return ans;
}

int parse(string str) {
    for (int i = 0; i < 169; ++i) {
        if (str == parse(i)) return i;
    }
    return 0;
}

int main(void) {
    string str;
    int n;
    vector<string> str_list;

    scanf(" %d ", &n);
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        str_list.push_back(str);
    }

    for (int i = 0; i < str_list.size(); ++i) {
        str = str_list[i];
        if (isdigit(str[0])) cout << parse(stoi(str)) << endl;
        else cout << parse(str) << endl;
    }
    return 0;
}