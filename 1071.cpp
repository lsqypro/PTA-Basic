//
// Created by lsqy on 2020/8/11.
//

/* 1071 小赌怡情 (15分)
 * 耗时：24:24.51
 *
 * 1. 先判断Total是否为0，可能Total初始值为0
 * 2. 其次判断玩家下注超过持有的筹码量
 * 3. 最后判断输赢
 */

#include <iostream>

using namespace std;

int main(void) {
//    对每一次游戏，根据下列情况对应输出（其中 t 是玩家下注量，x 是玩家当前持有的筹码量）：
//
//    玩家赢，输出 Win t!  Total = x.；
//    玩家输，输出 Lose t.  Total = x.；
//    玩家下注超过持有的筹码量，输出 Not enough tokens.  Total = x.；
//    玩家输光后，输出 Game Over. 并结束程序。
    int total_t, k, n1, b, t, n2;

    cin >> total_t >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n1 >> b >> t >> n2;
        if (total_t == 0) {
            cout << "Game Over." << endl;
            break;
        }
        else if (total_t-t < 0) printf("Not enough tokens.  Total = %d.\n", total_t);
        else if ((n2 > n1 && b == 1) || ((n2 < n1) && b == 0)) {
            total_t += t;
            printf("Win %d!  Total = %d.\n", t, total_t);
        }
        else {
            total_t -= t;
            printf("Lose %d.  Total = %d.\n", t, total_t);
        }
    }
    return 0;
}