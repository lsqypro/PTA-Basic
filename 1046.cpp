//
// Created by lsqy on 2020/8/9.
//

/* 1046 划拳 (15分)
 * 耗时：07:11.63
 *
 */

#include <iostream>

using namespace std;

int main(void) {
//    甲喊 甲划 乙喊 乙划
//    统计他们最后分别喝了多少杯酒
    int a = 0, b = 0;
    int a1, a2, b1, b2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a1 >> a2 >> b1 >> b2;
        if (a2 == a1 + b1) {
            if (b2 == a1 + b1) {

            }
            else b++;
        }
        else {
            if (b2 == a1 + b1) {
                a++;
            }
            else {

            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}