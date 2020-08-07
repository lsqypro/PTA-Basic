//
// Created by lsqy on 2020/8/7.
//

/* 1027 打印沙漏 (20分)
 * 耗时：37:44.91
 * 特别注意 1 * 这种情况（测试点1)
 */

#include <iostream>

using namespace std;

int main(void) {
    int n, remain = 0;
    char ch;

    cin >> n >> ch;  // 正整数N  >= 1
    int cnt = 1, i = 1;
    while (cnt < n) {
        i += 2;
        cnt += 2 * i;
    }
    if (cnt > n) {
        cnt -= 2 * i;
        i -= 2;
    }
    remain = n - cnt;

    // printf
    // 上 中
    int num = i;  // 第一行个数
    int j = 0;  // 空格数
    while (num > 0) {
        for (int k = 0; k < j; ++k) {
            cout << " ";
        }
        for (int l = 0; l < num; ++l) {
            cout << ch;
        }
        cout << endl;
        num -= 2;
        j++;
    }
    // 下
    j -= 2;
    num = 3;
    while (num <= i) {
        for (int k = 0; k < j; ++k) {
            cout << " ";
        }
        for (int l = 0; l < num; ++l) {
            cout << ch;
        }
        cout << endl;
        num += 2;
        j--;
    }
    cout << remain << endl;
    return 0;
}