//
// Created by lsqy on 2020/8/8.
//

/* 1037 在霍格沃茨找零钱 (20分)
 * 耗时：28:21.09
 * 17 * sickle = galleon
 * 29 * knut = sickle
 * 十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。
 * 在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
 */

#include <iostream>

using namespace std;

struct Money {
//        Galleon.Sickle.Knut
    int galleon, sickle, knut;
    int calc() {
        int knut_cnt = knut;
        knut_cnt += sickle * 29;
        knut_cnt += galleon * 17 * 29;
        return knut_cnt;

    }
    void init(int knut_cnt) {
        int opt = 1;
        if (knut_cnt < 0) {
            knut_cnt = -knut_cnt;
            opt = -1;
        }
        galleon = knut_cnt / (17*29);
        knut_cnt = knut_cnt % (17*29);

        sickle = knut_cnt / 29;
        knut_cnt = knut_cnt % 29;

        knut = knut_cnt;

        galleon *= opt;
    }
};

int main(void) {
    Money p, a, c;
//    应付的价钱 P 和他实付的钱 A，
//    Galleon.Sickle.Knut
    // input
    scanf("%d.%d.%d %d.%d.%d", &p.galleon, &p.sickle, &p.knut, &a.galleon, &a.sickle, &a.knut);

    c.init(a.calc()-p.calc());

    // output
    printf("%d.%d.%d\n", c.galleon, c.sickle, c.knut);
    return 0;
}