//
// Created by lsqy on 2020/8/6.
//

/* 1014 福尔摩斯的约会 (20分)
 * 耗时：50:23.79
 * 1. 星期：1，2串中，第 1 对相同的字符：A-G
 * 2. 小时：1，2串中，第 2 对相同的字符: 0-9、A-N
 * 3. 分钟：3，4串中，第 1 对相同的英文字母
3485dj D kxh4hhG E
2984ak D fkkkkgg E dsb
s&hg s fdk
d&Hy s cvnm
 */
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};  //
    string input[4];
    int count = 0;

    cin >> input[0] >> input[1] >> input[2] >> input[3];
    // 前两对
    for (int i = 0; i < input[0].size() && i < input[1].size(); ++i) {
        if (input[0][i] == input[1][i]) {
            char ch = input[0][i];
            if (count == 0 && isupper(ch) && ch <= 'G') { // 第 1 对相同的字符：A-G
                // 星期
                cout << days[ch - 'A'];
                count++;
            }
            else if (count == 1){ // 第 2 对相同的字符: 0-9、A-N
                // 时间 小时
                if (isdigit(ch)) {
                    printf(" %02d:", ch-'0');
                    break;
                }
                else if (isupper(ch) && ch <= 'N'){
                    printf(" %02d:", ch-'A' + 10 );
                    break;
                }
            }

        }
    }
    for (int i = 0; i < input[2].size() && i < input[3].size(); ++i) {
        if ((input[2][i] == input[3][i]) && isalpha(input[2][i])) {  // 第 1 对相同的英文字母
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}