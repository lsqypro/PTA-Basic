//
// Created by lsqy on 2020/8/11.
//

/* 1066 图像过滤 (15分)
 * 耗时：07:31.09
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int m, n, a, b, target;
    vector<int> pix;

    cin >> m >> n >> a >> b >> target;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int grey;
            cin >> grey;
            if (grey >= a && grey <= b) pix.push_back(target);
            else pix.push_back(grey);
        }
    }
    for (int i = 0; i < pix.size(); ++i) {
        printf("%03d", pix[i]);
        if ((i+1)%n == 0) cout << endl;
        else cout << " ";
    }
    return 0;
}