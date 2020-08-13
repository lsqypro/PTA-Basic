//
// Created by lsqy on 2020/8/13.
//

/* 1090 危险品装箱 (25分)
 * 耗时：27:09.72
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    int n, m, id1, id2, k;
    multimap<int, int> gmap;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> id1 >> id2;
        gmap.insert(make_pair(id1, id2));
        gmap.insert(make_pair(id2, id1));
    }

    for (int i = 0; i < m; ++i) {
        cin >> k;
        vector<int> goods;
        for (int j = 0; j < k; ++j) {
            cin >> id1;
            goods.push_back(id1);
        }
        bool is_ok = true;
        for (int j = 0; j < k; ++j) {
            multimap<int, int>::iterator it = gmap.find(goods[j]);
            int cnt = gmap.count(goods[j]);
            for (int l = 0; l < cnt; ++l, it++) {
                if (goods.end() != find(goods.begin(), goods.end(), it->second)) {
                    is_ok = false;
                    break;
                }
            }
        }
        if (is_ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
