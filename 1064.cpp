//
// Created by lsqy on 2020/8/11.
//

/* 1064 朋友数 (20分)
 * 耗时：11:09.30
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_friend_id(int value) {
    int ret = 0;
    while (value) {
        ret += value % 10;
        value /= 10;
    }
    return ret;
}

int cnt[10001] = {0};

int main(void) {
    int n;
    vector<int> fids;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        int fid = get_friend_id(tmp);
        if (cnt[fid]++ == 0) fids.push_back(fid);
    }
    sort(fids.begin(), fids.end());
    cout << fids.size() << endl;
    for (int i = 0; i < fids.size(); ++i) {
        cout << fids[i];
        if (i == fids.size() - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}