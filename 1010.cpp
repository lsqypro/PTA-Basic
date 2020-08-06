//
// Created by lsqy on 2020/8/6.
//

/* 1010 一元多项式求导 (25分)
 * 耗时：48:58.86
 *
 * 题目描述有毒
 */
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int n, p;
    cin >> n >> p;
    if(p == 0){
        cout << "0 0";
    }
    else {
        n = n * p;
        p--;
        cout << n << " " << p;
    }
    while (cin >> n >> p) {  // 读到文件结束符退出
        if(p == 0){
            break;
        }
        else {
            n = n * p;
            p--;
        }

        cout << " " << n << " " << p;
    }
    return 0;
}