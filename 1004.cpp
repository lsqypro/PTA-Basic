//
// Created by lsqy on 2020/8/6.
//

/* 1004 成绩排名 (20分)
 * 耗时：09:09.40
 */
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int min_score = 101, max_score = -1, tmp_score;
    int n;
    string min_uid, max_uid, tmp_uid;
    string max_name, min_name, tmp_name;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        //        姓名 学号 成绩
        cin >> tmp_name >> tmp_uid >> tmp_score;
        if (tmp_score < min_score) {
            min_score = tmp_score;
            min_name = tmp_name;
            min_uid = tmp_uid;
        }
        if (tmp_score > max_score) {
            max_score = tmp_score;
            max_name = tmp_name;
            max_uid = tmp_uid;
        }
    }
    cout << max_name << " " << max_uid << endl;
    cout << min_name << " " << min_uid << endl;
    return 0;
}