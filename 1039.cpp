//
// Created by lsqy on 2020/8/8.
//

/* 1039 到底买不买 (20分)
 * 耗时：27:13.22
 *
 * 1. 缺少：需要而没有的珠子数
 * 2. 多余：满足所有需要情况下，商品珠子总数-需要珠子总数
 */

#include <iostream>

using namespace std;

int main(void) {
    string sell, need;
    int ascii[128] = {0};
    cin >> sell >> need;

    for (int i = 0; i < sell.length(); ++i) {
        ascii[sell[i]]++;
    }
    int lack = 0;
    for (int i = 0; i < need.length(); ++i) {
        if (ascii[need[i]]) ascii[need[i]]--;
        else lack++;
    }

    if (lack) cout << "No " << lack << endl;
    else cout << "Yes " << sell.length()-need.length() << endl;

    return 0;
}