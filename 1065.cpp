//
// Created by lsqy on 2020/8/11.
//

/* 1065 单身狗 (25分)
 * 耗时：13:49.54
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m, i1, i2, partner[100000] = {0};
    vector<int> guest, singe;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> i1 >> i2;
        partner[i1] = i2;
        partner[i2] = i1;
    }

    cin >> m;
    guest.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> guest[i];
    }

    for (int i = 0; i < m; ++i) {
        // check
        vector<int>::iterator it = find(guest.begin(), guest.end(), partner[guest[i]]);
        if (it == guest.end()) singe.push_back(guest[i]);
    }
    sort(singe.begin(), singe.end());

    cout << singe.size() << endl;
    for (int i = 0; i < singe.size(); ++i) {
        printf("%05d", singe[i]);
        if (i != singe.size()-1) cout << " ";
        else cout << endl;
    }
    return 0;
}