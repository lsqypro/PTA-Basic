//
// Created by lsqy on 2020/8/12.
//

/* 1082 射击比赛 (20分)
 * 耗时：10:26.85
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int n, id, x, y;
    int score, max_score = -1, min_score = 500, max_id, min_id;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id >> x >> y;
        score = sqrt(x*x+y*y);
        if (score > max_score) {
            max_score = score;
            max_id = id;
        }
        if (score < min_score) {
            min_score = score;
            min_id = id;
        }
    }
    printf("%04d %04d\n", min_id, max_id);
    return 0;
}
