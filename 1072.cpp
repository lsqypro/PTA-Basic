//
// Created by lsqy on 2020/8/11.
//

/* 1072 开学寄语 (20分)
 * 耗时：13:52.19
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int goods_map[10000] = {0};

int main(void) {
    int n, m, stu_cnt = 0, goods_cnt = 0;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int id;
        cin >> id;
        goods_map[id] = 1;
    }
    for (int i = 0; i < n; ++i) {
        string name;
        vector<int> goods_list;
        int k, id;

        cin >> name >> k;
        for (int j = 0; j < k; ++j) {
            cin >> id;
            if (goods_map[id] == 1) {
                goods_list.push_back(id);
            }
        }
        if (goods_list.size() > 0) {
            cout << name << ": ";
            stu_cnt++;
        }
        for (int l = 0; l < goods_list.size(); ++l) {
            printf("%04d", goods_list[l]);
            if (l != goods_list.size()-1) cout << " ";
            else cout << endl;
            goods_cnt++;
        }
    }
    cout << stu_cnt << " " << goods_cnt << endl;
    return 0;
}