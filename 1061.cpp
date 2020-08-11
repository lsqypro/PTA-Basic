//
// Created by lsqy on 2020/8/11.
//

/* 1061 判断题 (15分)
 * 耗时：07:00.62
 *
 */

#include <iostream>

#define MAX 100

using namespace std;

int main(void) {
//    输入在第一行给出两个不超过 100 的正整数 N 和 M，分别是学生人数和判断题数量。
//    第二行给出 M 个不超过 5 的正整数，是每道题的满分值。
//    第三行给出每道题对应的正确答案，0 代表“非”，1 代表“是”。随后 N 行，每行给出一个学生的解答。数字间均以空格分隔。
    int n, m;
    int score[MAX] = {0}, ans[MAX] = {0};

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> score[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> ans[i];
    }
    for (int i = 0; i < n; ++i) {
        int sc = 0, in_ans;
        for (int j = 0; j < m; ++j) {
            cin >> in_ans;
            if (in_ans == ans[j]) sc += score[j];
        }
        cout << sc << endl;
    }
    return 0;
}