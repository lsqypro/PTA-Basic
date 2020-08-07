//
// Created by lsqy on 2020/8/7.
//

/* 1025 反转链表 (25分)
 * 耗时：54:30.98
 *
 * 测试点6 可能出现输入相同地址的数据，导致链表实际长度<cnt
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int list_data[100000], list_next[100000], list[100000];
    int root, cnt, addr, k;

    // input
    cin >> root >> cnt >> k;
    for (int i = 0; i < cnt; ++i) {
        cin >> addr;
        cin >> list_data[addr] >> list_next[addr];
    }

    // init list:测试点6 可能出现输入相同地址的数据，导致链表实际长度<cnt
    // 遍历链表求出实际长度
    cnt = 0;
    while (root != -1) {
        list[cnt++] = root;
        root = list_next[root];
    }

    // reverse
    for (int l = 0; l < cnt - cnt % k; l += k) {
        reverse(list + l, list + l + k);
    }

    // print
    for (int m = 0; m < cnt; ++m) {
        addr = list[m];
        printf("%05d %d ", addr, list_data[addr]);
        if (m == cnt - 1) printf("-1\n");
        else printf("%05d\n", list[m + 1]);
    }
    return 0;
}