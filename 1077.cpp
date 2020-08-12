//
// Created by lsqy on 2020/8/12.
//

/* 1077 互评成绩计算 (20分)
 * 耗时：19:41.42
 *
 */

#include <iostream>

using namespace std;

int main(void) {
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int sum = 0, s1, cnt = 0, ans, min_s = m+1, max_s = -1;
        cin >> s1;
        for (int j = 0; j < n-1; ++j) {
            int score;
            cin >> score;
            if (score >= 0 && score <= m) {
                min_s = min(min_s, score);
                max_s = max(max_s, score);
                sum += score, cnt++; //  [0,M]
            }
        }

        ans = (double(sum - min_s - max_s)/(cnt-2) + s1)/2.0+0.5;
        cout << ans << endl;
    }
    return 0;
}