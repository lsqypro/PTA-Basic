//
// Created by lsqy on 2020/8/6.
//

/* 1020 月饼 (25分)
 * 耗时：52:12.17
 * 1. 最大收益策略:优先卖出单价高的种类
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。
// 随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
struct Goods{
    double weight;
    double total_price;
    double price;
    void calc() {
        price = total_price / weight;
    }
};
int N, D;
double income = 0;
vector<Goods> goods;

int main(void) {
    cin >> N >> D;
    goods.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> goods[i].weight;  // 正数 库存量（以万吨为单位）
    }
    for (int i = 0; i < N; ++i) {
        cin >> goods[i].total_price;  // 正数 总售价（以亿元为单位）
        // 计算 单价
        goods[i].calc();
    }
    // 排序 单价递增
    sort(goods.begin(), goods.end(), [](const Goods &g1, const Goods &g2){
        return  g1.price > g2.price;
    });
    // 计算
    for (int j = 0; j < N && D > 0; ++j) {
        if (goods[j].weight <= D) {
            D -= goods[j].weight;
            income += goods[j].total_price;
        }
        else {
            // 销售时允许取出一部分库存
            income += D * goods[j].price;
            D = 0;
        }
    }

    /* 这种计算方法 3 测试点过不去
    double current = 0;  // 已经出售量
    while ((current < D) && (!goods.empty())) {
        if ((current + goods.begin()->weight) <= D) {
            current += goods.begin()->weight;
            income += goods.begin()->total_price;
        }
        else {
            income += (D - current) * goods.begin()->price;
            current = D;
        }
        goods.erase(goods.begin());
    }
    */

//    在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。
    printf("%0.2f\n", income);
    return 0;
}