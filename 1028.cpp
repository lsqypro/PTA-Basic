//
// Created by lsqy on 2020/8/7.
//

/* 1028 人口普查 (20分)
 * 耗时：20:44.91
 *
 * 测试点3 有效个数为零情况：cout << "0\n";
 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n, cnt = 0;
    // max_name: 年龄最大者姓名，max_date: 年龄最大者生日（年龄越大，生日日期越小, 初始值应给较大值）
    string max_name, min_name, max_date = "2014/09/07", min_date = "1814/09/05", name, date;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // 1814/09/05 及其之前生日为200岁及以上，（题目指不能 超过200 即小于等于200，但实际测试点等于200的也过滤掉）
        // 今天是 2014 年 9 月 6 日:未出生的生日是不合理的
        cin >> name >> date;
        if (date >= "2014/09/07" || date <= "1814/09/05") continue;
        if (date < max_date) {  // 日期越小，年龄越大
            max_date = date;
            max_name = name;
        }
        if (date > min_date) {
            min_date = date;
            min_name = name;
        }
        cnt++;
    }

    if (cnt == 0) cout << "0\n"; // 测试点3
    else cout << cnt << " " << max_name << " " << min_name << endl;  // 有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

    return 0;
}