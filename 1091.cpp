//
// Created by lsqy on 2020/8/13.
//

/* 1091 N-自守数 (15分)
 * 耗时：16:33.15
 *
 * 1. 计算平方时等较小幂时优先使用连乘方式（num*num）
 * 2. 使用pow函数可能出现整数的平方产生小数部分的情况
 */

#include <iostream>

using namespace std;

void check(int num) {
    for (int i = 1; i < 10; ++i) {
        int tmp = num * num * i;
        int tmp2 = num;
        bool flag = true;
        while (tmp2) {
            if (tmp%10 != tmp2%10) {
                flag = false;
                break;
            }
            tmp/=10, tmp2/=10;
        }
        if (flag) {
            cout << i << " " << num*num*i << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main(void) {
    int m, num;

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> num;
        check(num);
    }
    return 0;
}
