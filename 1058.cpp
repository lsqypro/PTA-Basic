//
// Created by lsqy on 2020/8/11.
//

/* 1058 选择题 (20分)
 * 耗时：56:33.40
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Question {
    int id, score, err_no;
    string ans;
    Question() {
        id = score = err_no = 0;
        ans = "";
    }
};

int main(void) {
    int n, m;
    vector<Question> qs;

    cin >> n >> m;
    qs.resize(m);
//    1 5 4 a b d e  一道题的满分值 选项个数 正确选项个数 所有正确选项
    for (int i = 0; i < m; ++i) {
        int cnt, true_cnt;
        cin >> qs[i].score >> cnt >> true_cnt;
        for (int j = 0; j < true_cnt; ++j) {
            char ch;
            cin >> ch;
            qs[i].ans += ch;
            qs[i].id = i + 1;
        }
    }

//    (2 b d) (1 e) (2 b c) (4 a b c d)
    vector<int> scores;
    for (int i = 0; i < n; ++i) {
        int score = 0;
        for (int j = 0; j < m; ++j) {
            int cnt;
            char ch;
            string ans = "";

            cin >> ch >> cnt;  // "(2"
            for (int k = 0; k < cnt; ++k) {
                cin >> ch;
                ans += ch;
            }
            cin >> ch;  // ")"
            // check
            if (ans == qs[j].ans) score += qs[j].score;
            else qs[j].err_no++;
        }
        scores.push_back(score);
    }

    sort(qs.begin(), qs.end(), [](const Question &q1, const Question &q2){
        if (q1.err_no != q2.err_no) return q1.err_no > q2.err_no;
        return q1.id < q2.id;
    });

    //    次数和编号: 次数 编号 编号
    int max_err_no = qs[0].err_no;
    int cnt = 0;
    for (int i = 0; i < qs.size(); ++i) {
        if (qs[i].err_no == max_err_no) cnt++;
        else break;
    }

    // output
    for (int i = 0; i < scores.size(); ++i) {
        cout << scores[i] << endl;
    }
    if (cnt == 0 || max_err_no == 0) cout << "Too simple" << endl;
    else {
        cout << max_err_no << " ";
        for (int i = 0; i < cnt; ++i) {
            cout << qs[i].id;
            if (i == cnt-1) cout << endl;
            else cout << " ";
        }
    }

    return 0;
}