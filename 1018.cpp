//
// Created by lsqy on 2020/8/6.
//

/* 1018 锤子剪刀布 (20分)
 * 耗时：20:47.79
 */
//如果解不唯一，则输出按字母序最小的解。

#include <iostream>

using namespace std;

int ac = 0, aj = 0, ab = 0;  // 甲，C,J,B赢次数
int bc = 0, bj = 0, bb = 0;  // 乙，C,J,B赢次数
int a1 = 0, a2 = 0, a3 = 0;  // 甲：赢 平 输
int b1 = 0, b2 = 0, b3 = 0;  // 乙：赢 平 输

void ckeck(char a, char b) {
    if (a == 'C') {
        if (b == 'C') {
            // 平
            a2++, b2++;
        }
        else if (b == 'J') {
            // a
            a1++, b3++;
            if (a == 'C') ac++;
            else if (a == 'J') aj++;
            else ab++;
        }
        else {
            // b
            a3++, b1++;
            if (b == 'C') bc++;
            else if (b == 'J') bj++;
            else bb++;
        }
    }
    else if (a == 'J') {
        if (b == 'C') {
            // b
            a3++, b1++;
            if (b == 'C') bc++;
            else if (b == 'J') bj++;
            else bb++;
        }
        else if (b == 'J') {
            // 平
            a2++, b2++;
        }
        else {
            // a
            a1++, b3++;
            if (a == 'C') ac++;
            else if (a == 'J') aj++;
            else ab++;
        }
    }
    else if (a == 'B') {
        if (b == 'C') {
            // a
            a1++, b3++;
            if (a == 'C') ac++;
            else if (a == 'J') aj++;
            else ab++;
        }
        else if (b == 'J') {
            // b
            a3++, b1++;
            if (b == 'C') bc++;
            else if (b == 'J') bj++;
            else bb++;
        }
        else {
            // 平
            a2++, b2++;
        }
    }
}

char most(int c, int j, int b) {
    if (c > j) {
        if (c > b) {
            return 'C';
        }
        else return 'B';
    }
    else if (c == j) {
        if (c > b) {
            return 'C';
        }
        else return 'B';
    }
    else {  // c < j
        if (j > b) {
            return 'J';
        }
        else return 'B';
    }
}

int main(void) {
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        char a, b;
        cin >> a >> b;
        ckeck(a, b);
    }
    cout << a1 << " " << a2 << " " << a3 << endl;
    cout << b1 << " " << b2 << " " << b3 << endl;
    cout << most(ac, aj, ab) << " " << most(bc, bj, bb) << endl;
    return 0;
}