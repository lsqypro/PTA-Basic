//
// Created by lsqy on 2020/8/11.
//

/* 1059 C语言竞赛 (20分)
 * 耗时：18:31.92
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int value) {
    int flag = sqrt(value);
    for (int i = 2; i <= flag; ++i) {
        if (value % i == 0) return false;
    }
    return true;
}

struct Person {
    int id, cnt, rank;

    Person() {
        id = rank = 0;
        cnt = 1;
    }

    string get() {
        if (cnt == 0) return "Checked";
        if (rank == 1) {
            cnt--;
            return "Mystery Award";
        }
        else if (is_prime(rank)) {
            cnt--;
            return "Minion";
        }
        else {
            cnt--;
            return "Chocolate";
        }
    }
};

int main(void) {
    int n, k, id;
    Person ids[10001];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id;
        ids[id].id = id;
        ids[id].rank = i + 1;
    }

    vector<string> ans;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string str_id;
        cin >> str_id;
        id = stoi(str_id);
        if (id == ids[id].id) ans.push_back(str_id+": "+ids[id].get());
        else ans.push_back(str_id + ": Are you kidding?");
    }
    for (string &item : ans) {
        cout << item << endl;
    }
    return 0;
}