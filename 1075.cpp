//
// Created by lsqy on 2020/8/12.
//

/* 1075 链表元素分类 (25分)
 * 耗时：34:55.72
 *
 * 1. 遍历三次链表，分别输出 (-E,0); [0,k]; (k,E)
 */

#include <iostream>

using namespace std;

int root, n, k;
struct Node{
    int data, next;
} list[100005];
int list_addr[100005];

int main(void) {
    cin >> root >> n >> k;

    for (int i = 0; i < n; ++i) {
        int addr;
        cin >> addr;
        cin >> list[addr].data >> list[addr].next;
    }
    // init list_addr
    int p = root, cnt = 0;
    while (p != -1) {
        list_addr[cnt++] = p;
        p = list[p].next;
    }
    // 负数
    bool first = true;
    int print_cnt = 0;
    for (int i = 0; i < cnt && print_cnt < cnt; ++i) {
        int addr = list_addr[i];
        if (list[addr].data < 0) {
            if (!first) printf(" %05d\n", addr);
            else first = false;
            printf("%05d %d", addr, list[addr].data);
            print_cnt++;
        }
    }
    // [0-k]
    for (int i = 0; i < cnt && print_cnt < cnt; ++i) {
        int addr = list_addr[i];
        if (list[addr].data >= 0 && list[addr].data <= k) {
            if (!first) printf(" %05d\n", addr);
            else first = false;
            printf("%05d %d", addr, list[addr].data);
            print_cnt++;
        }
    }
    // >k
    for (int i = 0; i < cnt && print_cnt < cnt; ++i) {
        int addr = list_addr[i];
        if (list[addr].data > k) {
            if (!first) printf(" %05d\n", addr);
            else first = false;
            printf("%05d %d", addr, list[addr].data);
            print_cnt++;
        }
    }
    cout << " -1" << endl;

    return 0;
}