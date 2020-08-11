//
// Created by lsqy on 2020/8/11.
//

/* 1068 万绿丛中一点红 (20分)
 * 耗时：02:11:29.07
 *
 * 即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大
 * 1. 独一无二：在整个矩阵中唯一
 * 2. 与其周围 8 个相邻像素的颜色差充分大, 边界上的点只需要判断周围在矩阵中的点
 *      也可以令矩阵外的点像素为一个极大值(比2^24的两倍还大)，即保证了颜色差充分大
 *      差值可能正，可能负
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, tol;
int dir[8][2] = { {-1,-1},{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 } };
vector<vector<int>> matrix;
int pix_map[99999999] = {0};

bool judge(int i, int j) {
    for (int k = 0; k < 8; ++k) {
        int di = i + dir[k][1];
        int dj = j + dir[k][0];
        if (di >= 0 && di < n && dj >= 0 && dj < m && abs(matrix[i][j]-matrix[di][dj]) <= tol)
            return false;
    }
    return true;
}

int main(void) {
    int x, y, cnt = 0;

    cin >> m >> n >> tol;
    matrix.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            pix_map[matrix[i][j]]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (judge(i, j) && pix_map[matrix[i][j]] == 1) {
                x = j + 1, y = i + 1;
                cnt++;
            }
        }
    }

    if (cnt == 0) cout << "Not Exist" << endl;
    else if (cnt > 1) cout << "Not Unique" << endl;
    else cout << "(" << x << ", " << y << "): " << matrix[y-1][x-1] << endl;

    return 0;
}