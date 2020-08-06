//
// Created by lsqy on 2020/8/6.
//

/* 1008 数组元素循环右移问题 (20分)
 * 耗时：25:00.69
 */
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int arr[100];
int n, m;

void move_1() {
    // 不使用额外数组 测试点3超时
    int index = m;
    do {
        for (int i = 0; i < m; ++i) {
            swap(arr[i%n], arr[(index+i)%n]);
        }
        index += m;
    } while (index < n);
    // 打印
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i != n-1) putchar(' ');
    }
}

void move_2() {
    int tmp[100];
    // 使用另外数组
    // 移动次数：n
    for (int i = 0; i < n; ++i) {
        tmp[(m+i)%n] = arr[i];
    }
    // 打印
    for (int i = 0; i < n; ++i) {
        printf("%d", tmp[i]);
        if (i != n-1) putchar(' ');
    }
}

int main(void) {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &arr[i]);
    }
    // 移动
    move_2();
    return 0;
}