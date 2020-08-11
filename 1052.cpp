//
// Created by lsqy on 2020/8/10.
//

/* 1052 卖个萌 (20分)
 * 耗时：30:43.13
 *
 * 1. getline(cin, str) 读入一行字符，题目保证有3行
 * 2. 根据'[',']'符号对解析表情，放入相应vector中
 * 3. 用户请求的表情编号可能不合法（<1 或 > size)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> hands, eyes, mouths;

string emoji(int lh, int le, int m, int re, int rh) {
    lh--, le--, m--, re--, rh--;
    if (lh >= int(hands.size()) || le >= int(eyes.size())
        || m >= int(mouths.size()) || re >= int(eyes.size())
        || rh >= int(hands.size())
        || lh < 0 || le < 0 || m < 0 || re < 0 || rh < 0)
        return "Are you kidding me? @\\/@";
    //    顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从 1 开始），数字间以空格分隔

    //    [左手]([左眼][口][右眼])[右手]
    return hands[lh]+"("+eyes[le]+mouths[m]+eyes[re]+")"+hands[rh];
}

void parse(vector<string> &target, string str) {
    bool start = false;
    string tmp;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '[') {
            start = true;
        }
        else if (str[i] == ']') {
            target.push_back(tmp);
            tmp.clear();
            start = false;
        }
        else if (start) {
            tmp.push_back(str[i]);
        }
    }
}

int main(void) {
//    前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号 []内
    string str;
    // 手
    getline(cin, str);
    parse(hands, str);
    // 眼
    getline(cin, str);
    parse(eyes, str);
    // 口
    getline(cin, str);
    parse(mouths, str);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int lh, le, m, re, rh;
        cin >> lh >> le >> m >> re >> rh;
        cout << emoji(lh, le, m, re, rh) << endl;
    }

    return 0;
}