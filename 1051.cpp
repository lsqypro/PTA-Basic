//
// Created by lsqy on 2020/8/10.
//

/* 1051 复数乘法 (15分)
 * 耗时：23:42.25
 *
 * 1. 当负数保留2位小数后结果为0时，会输出-0.00
 *      printf("%0.2f\n", -0.00123);  // -0.00
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    double r1, p1, r2, p2, r3, p3;
    double a, b;

    cin >> r1 >> p1 >> r2 >> p2;

    r3 = r1 * r2;
    p3 = p1 + p2;
    a = r3 * cos(p3);
    b = r3 * sin(p3);

    if (abs(a) < 0.01) a = 0;
    if (abs(b) < 0.01) b = 0;

    if (b < 0) printf("%0.2f%0.2fi\n", a, b);
    else printf("%0.2f+%0.2fi\n", a, b);

    return 0;
}