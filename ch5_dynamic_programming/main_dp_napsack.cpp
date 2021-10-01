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

// 「緩和] max
auto chmax = [](auto &a, auto b) {
    // dp[i]のチャンピオン(最小コスト)をに更新する

    if (a < b) {
        a = b;
    }
};


// N: 品物の個数
// W: ナップサックの容量
// i: N個{i=0~N-1}中i番目の荷物を選ぶ
// j: 現在のナップサックの重さ

// 1) i番目の品物を選ぶとき
// i番目の品物を選ぶ前のナップサックの状態      　　　　　　　　　　 dp[i-1][w-weight[i]]
// i番目の品物を選んだ場合のナップサックの状態が(i+1,w)になるならば、chmax(dp[i+1][w], dp[i][w-weight[i]] + value[i])

// 2) i番目の品物を選ばないとき
// 重さも価値も特に変化しない
// chmax(dp[i+1][w], dp[i][w])



int main(int, char **) {

    // 入力
    int N; long long W;

    std::printf("品物の個数Nを指定してください\n");
    std::cin >> N;
    std::printf("ナップサックの容量Wを指定してください\n");
    std::cin >> W;

    std::vector<long long> weight(N); // 品物iの重みw
    std::vector<long long> value(N);  // 品物iの価値v
    for (int i = 0; i < N; ++i) {
        std::printf("品物%dの重みw[%d]を指定してください", i, i);
        std::cin >> weight[i];
        std::printf("品物%dの価値v[%d]を指定してください", i, i);
        std::cin >> value[i];
        std::cout << std::endl;
    }

    std::printf("品物(重み,価値)\n");
    for (int i = 0; i < N; ++i) {
        std::printf("(%d,%d) ", weight[i], value[i]);
    }
    std::cout << "ナップサックの容量" << W << std::endl;    

    // DPテーブル定義
    std::vector<std::vector<long long>> dp(N+1, std::vector<long long>(W+1, 0));

    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {

            // i番目の品物を選ぶ場合
            if (w - weight[i] >= 0) { // ナップサックの容量wが増えるような品物i
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }

            // i番目の品物を選ばない場合
            chmax(dp[i + 1][w], dp[i][w]);
        }
    }

    // 最適値の出力
    std::cout << "最適値 " << dp[N][W] << std::endl;

    return 0;
}