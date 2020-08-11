//
// Created by lsqy on 2020/8/11.
//

/* 1062 最简分数 (20分)
 * 耗时：24:57.88
 *
 * 1. 现给定两个不相等的正分数,输入的两个分数大小顺序不确定
 * 2. 在进行分数比较要么使用double相除，要么转为乘法（通分后比较分子）
 */

#include <iostream>
#include <cmath>

using namespace std;

int divisor(int n, int m) {
    return m ? divisor(m, n % m) : n;
}

bool check(int n, int m) {
    if (divisor(n, m) == 1) return true;
    else return false;
}

int main(void) {
    int n1, m1, n2, m2, k;

    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if (n1 * m1 > m1 * n2) {
        swap(n1, n2);
        swap(m1, m2);
    }
    int start = n1*k/m1-1, stop = n2*k/m2+1;
    int n = start;
    bool first = true;
    while (n <= stop) {
        if (n*m1 > n1*k && n*m2 < n2*k && check(n, k)) {
            if (!first) cout << " ";
            else first = false;
            cout << n << "/" << k;
        }
        n++;
    }
    cout << endl;

    return 0;
}