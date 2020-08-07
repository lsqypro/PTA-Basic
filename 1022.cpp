//
// Created by lsqy on 2020/8/7.
//

/* 1022 D进制的A+B (20分)
 * 耗时：4:39.36
 */

#include <iostream>
#include <string>

using namespace std;

string parse(int num, int d) {
    string ret;

    while (num) {
        int p = num % d;
        ret.insert(0, 1, p+'0');
        num /= d;
    }
    if (ret.empty()) ret = "0";
    return ret;
}

int main(void) {
    int a, b, d;
    cin >> a >> b >> d;
    cout << parse(a+b, d) << endl;
    return 0;
}