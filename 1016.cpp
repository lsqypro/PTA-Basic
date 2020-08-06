//
// Created by lsqy on 2020/8/6.
//

/* 1016 部分A+B (15分)
 * 耗时：9:01.64
 */
#include <iostream>

using namespace std;

int calc(int num, int d) {
    int cnt = 0;
    while (num) {
        if (num % 10 == d) cnt++;
        num /= 10;
    }
    return cnt;
}

int make(int d, int cnt) {
    int ret = 0;
    for (int i = 0; i < cnt; ++i) {
        ret = ret * 10 + d;
    }
    return ret;
}

int main(void) {
    int a, da, b, db;
    int pa, pb;
    cin >> a >> da >> b >> db;
    pa = make(da, calc(a, da));
    pb = make(db, calc(b, db));
    cout << pa + pb << endl;
    return 0;
}