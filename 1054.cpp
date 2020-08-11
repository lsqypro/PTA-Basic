//
// Created by lsqy on 2020/8/11.
//

/* 1054 求平均值 (20分)
 * 耗时：01:13:42.39
 *
 * 1. 注意只有一个合法数字时 输出"The average of 1 number is Y", 中"number"是单数形式
 */

#include <iostream>
#include <cmath>

using namespace std;

bool check(string &str, double &value) {
//    一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位
//    5 -3.2 aaa 9999 2.3.4 7.123 2.35
    int dot = 0, dot_p;
    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (!isdigit(ch)) {
            if (ch == '-') {
                if (i != 0) return false;
            }
            else if (ch == '.') {
                if (dot > 0) return false;
                dot++;
                dot_p = i;
            }
            else return false;
        }
    }

    value = stod(str);

    if (fabs(value) > 1000.00) return false;

    if (dot > 0) {
        if ((str.length()-dot_p-1) > 2) return false;
    }

    return true;
}

int main(void) {
    string str;
    double value, sum = 0, average;
    int n, cnt = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        if (check(str, value)) {
            sum += value;
            cnt++;
        }
        else cout << "ERROR: " << str << " is not a legal number" << endl;
    }
    if (cnt) {
        average = sum / cnt;
        if (cnt == 1) printf("The average of %d number is %0.2f\n", cnt, average);
        else printf("The average of %d numbers is %0.2f\n", cnt, average);
    }
    else printf("The average of 0 numbers is Undefined\n");

    return 0;
}