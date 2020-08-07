//
// Created by lsqy on 2020/8/7.
//

/* 1026 程序运行时间 (15分)
 * 耗时：9:56.15
 * 两次获得的时钟打点数肯定不相同，即 C1 < C2
 * hh:mm:ss（即2位的 时:分:秒）格式输出；不足 1 秒的时间四舍五入到秒。
 */

#include <iostream>

using namespace std;

int main(void) {
    int c1, c2, sec;
    int h, m, s;
    // 奇怪的是错误的代码运行通过.. cin >> c2 >> c2;
//    cin >> c2 >> c2;
//    sec = (c2 - c1) / 100;

    cin >> c1 >> c2;
    sec = (c2 - c1) / 100.0 + 0.5;
    h = sec / 3600;
    sec = sec - h * 3600;
    m = sec / 60;
    sec = sec - m * 60;
    s = sec;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}