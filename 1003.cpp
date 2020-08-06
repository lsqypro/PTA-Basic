//
// Created by lsqy on 2020/8/6.
//

/* 1003 我要通过！ (20分)
 * 耗时 01:40:18.70
 * 1. 仅有P,A,T三类字符，不能多，不能少
 * 2. xPATx：x为空或为A
 * 如：PAT，AAPATAA
 * 3. aPbTc正确则aPbATca正确
 * 总结2,3：P前面的A的个数 乘以 P和T之间的A的个数 等于 T后面的A的个数（参考：https://blog.csdn.net/qq_41982223/article/details/104659575）
 *
 * 读这种题目就是浪费年轻人时间
 */

#include <iostream>
#include <string>

using namespace std;

bool check(string &str) {
    int np = 0, na = 0, nt = 0; // P,A,T字符总数
    int n1 = 0, n2 = 0, n3 = 0; // P前A总数，P,T之间A总数，T之后A总数
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == 'P') {
            if (np == 1) return false; // P只有一个
            np++;
        }
        else if (str[i] == 'T') {
            if (nt == 1 || np == 0) return false; // T只有一个, T在P之后
            nt++;
        }
        else if (str[i] == 'A') {
            if (np == 0) {
                // P之前
                na++, n1++;
            }
            else if (nt == 0) {
                // P后T前
                na++, n2++;
            }
            else {
                // T之后
                na++, n3++;
            }
        }
        else {
            return false; // 出现其他字符
        }
    }
//    P前面的A的个数 乘以 P和T之间的A的个数 等于 T后面的A的个数
    if (np == 1 && na > 0 && nt == 1 && n1 * n2 == n3) return true;
    return false;
}

int main(void) {
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (check(str)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
