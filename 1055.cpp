//
// Created by lsqy on 2020/8/11.
//

/* 1055 集体照 (25分)
 * 耗时：58:11.39
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
    string name;
    int height;
};

int main(void) {
    int n, k;
    vector<Person> ps;

    cin >> n >> k;
    ps.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].name >> ps[i].height;
    }

    // sort
    sort(ps.begin(), ps.end(), [](const Person &p1, const Person &p2){
        if (p1.height != p2.height) return p1.height > p2.height;
        else return p1.name < p2.name;
    });

    vector<int> site;
    site.resize(n);
    int num = n/k;
    for (int row = 0, i = 0; row < k; ++row) {
        int cnt = num;
        if (row == 0) cnt += n%k;
        int center = cnt/2+1 + i - 1;
//        先右后左交替入队, 先-，后+
        site[center] = i++;
        int delta = 1;
        for (int j = 1; j < cnt;) {
            site[center-delta] = i++; j++;
            if (j >= cnt) break;
            site[center+delta] = i++; j++;
            delta++;
        }
    }

    // output
    for (int i = 0, row = 0; i < n; row++) {
        int cnt = num;
        if (row == 0) cnt += n%k;
        while (cnt--) {
            cout << ps[site[i++]].name;
            if (cnt == 0) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}