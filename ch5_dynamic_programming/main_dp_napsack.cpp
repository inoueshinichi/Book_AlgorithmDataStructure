/**
 * @file main_dp_napsack.cpp
 * @author your name (you@domain.com)
 * @brief ナップサック問題 (動的計画法)
 * @version 0.1
 * @date 2021-09-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>

const long long INF = 1LL << 60; // 十分大きな値(2^60)

// 「緩和]
auto chmax = [](auto &a, auto b) {
    // dp[i]のチャンピオン(最小コスト)をに更新する
    if (a < b)
    {
        a = b;
    }
};


// N: 品物の個数
// W: ナップサックの容量
// i: N個{i=0~N-1}中i番目の荷物を選ぶ
// j: 現在のナップサックの重さ

// i番目の品物を選ぶ前のナップサックの状態 -> dp[i-1]


int main(int, char **) {

    // 入力

    // 解法パターン
    bool is_ver0 = false;
    bool is_ver1 = false;

    if (is_ver0) {

    }

    if (is_ver1) {

    }

    return 0;
}