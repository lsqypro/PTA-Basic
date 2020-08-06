//
// Created by lsqy on 2020/8/6.
//

/* 1005 继续(3n+1)猜想 (25分)
 * 耗时：24:25.10
 * 计算每一次输入数值所覆盖的数，n = (3 * n + 1) 可能导致n变大
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int input[100] = {0};
int key[101] = {0}; // n = (3 * n + 1) 可能导致n变大

void calc(int value) {
    bool first = true;
    while (value != 1) {
        // 记录被value“覆盖”的数
        if (!first && value < 101 ) {
            key[value] = 1;
        }
        first = false;
        if (value % 2 == 0) {
            value /= 2;
        }
        else {
            value = (3 * value + 1) / 2;
        }
    }
}

int compare(const void *a, const void *b) {
    return *(int *)a < *(int *)b;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    // 从大到小排序
    qsort(input, n, sizeof(int), compare);
    // 计算每一个输入的数所覆盖的值
    for (int i = 0; i < n; ++i) {
        calc(input[i]);
    }
    // 从大到小输出
    bool first = true;
    for (int j = 0; j < n; ++j) {
        if (key[input[j]] == 0) {
            if (!first) {
                cout << " ";
            }
            first = false;
            cout << input[j];
        }
    }

    return 0;
}