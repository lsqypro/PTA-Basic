//
// Created by lsqy on 2020/8/6.
//

/* 1017 A除以B (20分)
 * 耗时：26:29.64
 * 本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。
 * 超大数运算
 */
#include <iostream>
#include <string>

using namespace std;

struct Int{
    string value;

    friend istream &operator>>(istream &in, Int &item);

    friend ostream &operator<<(ostream &out, const Int &item);

    Int operator/(Int &another){
        Int ret;
        int a = stoi(another.value);
        int tmp = 0;  // 借位

        for (int i = 0; i < this->value.size(); ++i) {
            int curt = this->value[i] - '0';
            int q = (tmp*10+curt) / a;
            tmp = (tmp*10+curt) % a;

            if (q == 0 && ret.value.size() == 0) continue;
            ret.value.push_back('0' + q);
        }
        if (ret.value.size() == 0) ret.value = "0";
        return ret;
    }

    Int operator%(Int &another){
        Int ret;
        int a = stoi(another.value);
        int tmp = 0;  // 借位

        for (int i = 0; i < this->value.size(); ++i) {
            int curt = this->value[i] - '0';
            tmp = (tmp*10+curt) % a;
        }
        ret.value = to_string(tmp);

        return ret;
    }
};

istream &operator>>(istream &in, Int &item) {
    in >> item.value;
    return in;
}

ostream &operator<<(ostream &out, const Int &item) {
    cout << item.value;
    return out;
}

int main(void) {
    Int a, b, q, r;
    cin >> a >> b;
    q = a / b;
    r = a % b;
    cout << q << " " << r << endl;
    return 0;
}

/* 核心算法
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string a, q;
    int b, r;
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        int curt = a[i]-'0';
        int qi = (r * 10 + curt) / b;  // 商
        r = (r * 10 + curt) % b;  // 余数
        if (qi == 0 && q.size() == 0) continue;  // 有效数字不为0
        q.push_back(qi+'0');
    }
    if (q.size() == 0) q = "0";
    cout << q << " " << r << endl;
    return 0;
}
 * */