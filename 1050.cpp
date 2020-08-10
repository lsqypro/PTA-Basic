//
// Created by lsqy on 2020/8/9.
//

/* 1050 螺旋矩阵 (25分)
 * 耗时：53:26.68
 *
 * 1. 要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。
 *      1. m >= n: n从sqrt(num)向下取值
 *      2. m*n == num：num % n == 0, m = num / n
 *      3. m-n最小：在满足1,2时向下第一个取得第一个值
 * 2. 螺旋矩阵
 *      1. 顺时针从外圈向内收缩 98 95 93 81 76 76 60 58 53 42 第一圈，37 20 第二圈
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int N, m, n;
    vector<int> seq;

    // input
    cin >> N;
    seq.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    // calculate m & n
    for (int i = sqrt(N); i > 0; --i) {
        if (N % i == 0) {
            m = N / i;
            n = i;
            break;
        }
    }

    // sort
    sort(seq.begin(), seq.end());
    reverse(seq.begin(), seq.end());

    vector<int> matrix; // row=i,col=j : matrix[n*(i)+(j)]
    matrix.resize(N);

    for (int i = 0, level = 0; i < N; ++level) {
        // top row
        for (int j = 0; j < n - 2*level && i < N; ++j) {
            matrix[n*(level)+(level+j)] = seq[i++];
        }
        // right column
        for (int j = 0; j < m-2*level-1 && i < N; ++j) {
            matrix[n*(level+1+j)+(n-1-level)] = seq[i++];
        }
        // button row
        for (int j = 0; j < n-2*level-1 && i < N; ++j) {
            matrix[n*(m-1-level)+(n-1-level-1-j)] = seq[i++];
        }
        // left column
        for (int j = 0; j < m-2*level-2 && i < N; ++j) {
            matrix[n*(m-2-level-j)+(level)] = seq[i++];
        }
    }

    // output
    for (int i = 0; i < matrix.size(); ++i) {
        cout << matrix[i];
        if ((i+1) % n == 0) cout << endl;
        else cout << " ";
    }

    return 0;
}