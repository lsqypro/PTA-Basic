//
// Created by lsqy on 2020/8/13.
//

/* 1092 最好吃的月饼 (20分)
 * 耗时：11:49.78
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Moon{
    int total;
    int id;
    Moon() {
        total = id = 0;
    }
};

int main(void) {
    int n, m, cnt, max_cnt;
    vector<Moon> mv;

    cin >> n >> m;
    mv.resize(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cnt;
            mv[j].total += cnt;
            mv[j].id = j+1;
        }
    }

    sort(mv.begin(), mv.end(), [](const Moon &m1, const Moon &m2){
        if (m1.total != m2.total) return m1.total > m2.total;
        else return m1.id < m2.id;
    });

    max_cnt = mv[0].total;
    cout << max_cnt << endl;
    cout << mv[0].id;
    for (int i = 1; i < mv.size(); ++i) {
        if (mv[i].total == max_cnt) cout << " " << mv[i].id;
    }
    cout << endl;
    return 0;
}
