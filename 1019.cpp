//
// Created by lsqy on 2020/8/6.
//

/* 1019 数字黑洞 (20分)
 * 耗时：21:06.19
 * 1. 测试点5 a = 6174
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 非递增排序
int noup(int num) {
    int ret = 0;
    int arr[4] = {0};

    for (int i = 0; i < 4; ++i) {
        arr[i] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        ret = ret * 10 + arr[i];
    }
    return ret;
}

//非递减排序
int nolow(int num) {
    int ret = 0;
    int arr[4] = {0};

    for (int i = 0; i < 4; ++i) {
        arr[i] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        ret = ret * 10 + arr[i];
    }
    return ret;
}

int main(void) {
    int a, b, c;

    cin >> a;
    a = noup(a);  // 卡测试点5,推测测试点5输入a为6174
    while (a != 6174 && a != 0) {
        a = noup(a);
        b = nolow(a);
        c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);
        a = c;
    }
    return 0;
}