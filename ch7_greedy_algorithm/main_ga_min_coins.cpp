/**
 * @file main_ga_min_coins.cpp
 * @author your name (you@domain.com)
 * @brief 貪欲法 最小なコイン枚数
 * @version 0.1
 * @date 2021-10-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


// コインの金額
const vector<int> coin_val = {500, 100, 50, 10, 5, 1};

int main(int, char**)
{
    cout << "手持ちの硬貨の種類: 500, 100, 50, 10, 5, 1" << endl;

    // コイン枚数
    vector<int> coin_num(coin_val.size());
    for (int i = 0; i < coin_num.size(); ++i)
    {
        cout << (i+1) << "枚目: ";
        cin >> coin_num[i];
    }

    // 支払い金額
    int X;
    cout << "支払い金額: ";
    cin >> X;

    // 貪欲法
    vector<int> used_nums(coin_val.size(), 0);
    int sum;
    for (int i = 0; i < coin_val.size(); ++i)
    {
        int add = X / coin_val[i];

        // 枚数の制限
        if (add > coin_num[i]) add = coin_num[i];

        X -= add * coin_val[i];
        used_nums[i] = add;
        sum += add;
    }

    cout << "使用したコインの枚数は" << sum << "です。" << endl;
    for (int i = 0; i < used_nums.size(); ++i)
    {
        printf("%d: %d\n", coin_val[i], used_nums[i]);
    }
}