//
// Created by lsqy on 2020/8/8.
//

/* 1034 有理数四则运算 (20分)
 * 耗时：42:21.76
 * 1. 其中分子和分母全是整型范围内的整数，但进行计算时可能溢出，使用long long
 * 2. format 函数中使用两个long long 相乘的话，测试点2可能会导致long long 溢出
 */

#include <iostream>
#include <string>

using namespace std;

long long divisor(long long a, long long b) {
    return b ? divisor(b, a % b) : a;
}

string format(long long a, long long b) {
    // 特殊数字
    if (b == 0) return "Inf";
    if (a == 0) return "0";

    // 判断符号
    bool is_minus = true;
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) is_minus = false;
    a = abs(a), b = abs(b);

    // 最简形式 k a/b
    // k
    long long k = 0;
    if (a >= b) {
        k = a / b;
        a = a % b;
    }
    // a/b 约分,
    long long d = divisor(a, b);
    a /= d, b /= d;

    // formatting
    // 2/3 + (-2) = (-1 1/3)
    string ret_str;
    if (is_minus) ret_str.append("(-");
    if (k > 0) ret_str.append(to_string(k));
    if (k > 0 && a > 0) ret_str.append(" ");
    if (a > 0) ret_str.append(to_string(a)+"/"+to_string(b));
    if (is_minus) ret_str.append(")");

    return ret_str;
}

int main(void) {
    long long a1, b1, a2, b2, aans, bans;
    char ch;
    cin >> a1 >> ch >> b1 >> a2 >> ch >> b2;

    // +
    aans = a1 * b2 + b1 * a2;
    bans = b1 * b2;
    cout << format(a1, b1) << " + " << format(a2, b2) << " = " << format(aans, bans) << endl;

    // -
    aans = a1 * b2 - b1 * a2;
    bans = b1 * b2;
    cout << format(a1, b1) << " - " << format(a2, b2) << " = " << format(aans, bans) << endl;

    // *
    aans = a1 * a2;
    bans = b1 * b2;
    cout << format(a1, b1) << " * " << format(a2, b2) << " = " << format(aans, bans) << endl;

    // /
    aans = a1 * b2;
    bans = b1 * a2;
    cout << format(a1, b1) << " / " << format(a2, b2) << " = " << format(aans, bans) << endl;

    return 0;
}