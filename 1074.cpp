//
// Created by lsqy on 2020/8/12.
//

/* 1074 宇宙无敌加法器 (20分)
 * 耗时：34:12.34
 *
 * 1. 测试点5：类似
 *      30527
        00
        00
 */

#include <iostream>

using namespace std;

int main(void) {
    string sys_table, nm1, nm2, ans;

    cin >> sys_table >> nm1 >> nm2;
    int max_length = max(nm1.length(), nm2.length());
    int index = 0, carry = 0;

    while (index < max_length) {
        int n1 = 0, n2 = 0;
        if (index < nm1.length()) n1 = nm1[nm1.length()-1-index]-'0';
        if (index < nm2.length()) n2 = nm2[nm2.length()-1-index]-'0';

        int a = n1 + n2 + carry;
        int sys_num = sys_table[sys_table.length()-1-index]-'0';
        if (sys_num == 0) sys_num = 10;

        ans.insert(0, 1, a % sys_num + '0');
        carry = a / sys_num;
        index++;
    }
    if (carry == 1) ans = "1" + ans;

    for (int i = 0; i < ans.length(); ++i) {
        if (ans[i] != '0') {
            ans = ans.substr(i, ans.length());
            break;
        }
    }

    if (ans[0] != '0')
        cout << ans << endl;
    else cout << "0" << endl;

    return 0;
}