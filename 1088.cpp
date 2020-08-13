//
// Created by lsqy on 2020/8/13.
//

/* 1088 三人行 (20分)
 * 耗时：24:39.78
 *
 * 1. 可以确定甲的能力值为2位正整数，乙是甲两位数字调换，也是正整数
 * 2. 而对于乙：甲乙两人能力差是丙的能力值的 X 倍，计算乙，abs(a-b)/x可能产生小数，应使用double保存乙的能力值（测试点4）
 */

#include <iostream>

using namespace std;

int main(void) {
    int m, x, y, cnt = 0;

    cin >> m >> x >> y;
    int max_a = 0, mb;
    double mc;
    for (int i = 10; i <= 99; ++i) {
        int a = i;
        int b = a%10*10 + a/10;
        double c = abs(a-b)/double(x);
        if (b == c * y) {
            cnt++;
            if (a > max_a) {
                max_a = a;
                mb = b;
                mc = c;
            }
        }
    }
    if (cnt >= 1) {
        cout << max_a;
        if (m < max_a) cout << " Cong";
        else if (m == max_a) cout << " Ping";
        else cout << " Gai";

        if (m < mb) cout << " Cong";
        else if (m == mb) cout << " Ping";
        else cout << " Gai";

        if (m < mc) cout << " Cong";
        else if (m == mc) cout << " Ping";
        else cout << " Gai";
        cout << endl;
    }
    else cout << "No Solution" << endl;
    return 0;
}
