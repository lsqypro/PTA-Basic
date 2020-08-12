//
// Created by lsqy on 2020/8/12.
//

/* 1073 多选题常见计分法 (20分)
 * 耗时：39:27.650
 *
 * 1. 最后输出错得最多的题目选项的信息：学生答案与正确答案不同的选项
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Question{
    static int max_err_no;
    int id, opt_cnt, suc_opt_cnt, err_opt_cnt[5], suc_opt[5];
    double score;

    Question() {
        opt_cnt = 0;
        for (int i = 0; i < 5; ++i) {
            err_opt_cnt[i] = suc_opt[i] = 0;
        }
    }

    double check_score(int *in_opt) {
        int cnt = 0;
        bool is_true = true;
        for (int i = 0; i < opt_cnt; ++i) {
            if (in_opt[i] == 1) {
                if (suc_opt[i] != 1) is_true = false;
                else cnt++;
            }
            if (in_opt[i] != suc_opt[i]) max_err_no = max(max_err_no, ++err_opt_cnt[i]);
        }

        if (is_true) {
            if (cnt == suc_opt_cnt) return score;
            else return score/2;
        }
        else return 0;
    }

    void print_err() {
        for (int i = 0; i < opt_cnt; ++i) {
            if (err_opt_cnt[i] == max_err_no)
                cout << max_err_no << " " << id << "-" << char(i+'a') << endl;
        }
    }
};
int Question::max_err_no = 0;

int main(void) {
    int n, m;
    vector<Question> ques_v;

    cin >> n >> m;
    // input question
    ques_v.resize(m);
    for (int i = 0; i < m; ++i) {
        char ch;
        ques_v[i].id = i+1;
        cin >> ques_v[i].score >> ques_v[i].opt_cnt >> ques_v[i].suc_opt_cnt;
        for (int j = 0; j < ques_v[i].suc_opt_cnt; ++j) {
            cin >> ch;
            ques_v[i].suc_opt[ch-'a'] = 1;
        }
    }

    // check
    vector<double> score_ve;
    for (int i = 0; i < n; ++i) {
        double score = 0;
        for (int k = 0; k < m; ++k) {
            int cnt, in_opt[5] = {0};
            char ch;
            cin >> ch >> cnt;  // "(2"
            for (int j = 0; j < cnt; ++j) {
                cin >> ch;
                in_opt[ch-'a'] = 1;
            }
            cin >> ch; // ")"
            score += ques_v[k].check_score(in_opt);
        }
        score_ve.push_back(score);
    }

    // output
    // score
    for (auto &i : score_ve) {
        printf("%0.1f\n", i);
    }
    // question

    if (Question::max_err_no == 0) cout << "Too simple" << endl;
    else {
        for (auto &i : ques_v) {
            i.print_err();
        }
    }

    return 0;
}
