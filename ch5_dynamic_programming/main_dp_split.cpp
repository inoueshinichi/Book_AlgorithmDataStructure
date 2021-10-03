/**
 * @file main_dp_split.cpp
 * @author your name (you@domain.com)
 * @brief 動的計画法　最小コストになるような区間分割
 * @version 0.1
 * @date 2021-10-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <random>


template <typename T>
void chmin(T& a, T b) {
    if (a > b)
        a = b;
}

const int INF = 1 << 29; // 十分大きな値(2^29)

int main(int, char**) {

    // 入力
    std::printf("個数を指定してください\n");
    int N;
    std::cin >> N;



    // 区間コスト
    std::printf("区間コストを設定します。\n");
    std::vector<std::vector<long long>> c(N+1, std::vector<long long>(N+1, 0));
    int seed = 1990;
    std::mt19937 e(seed);
    std::uniform_int_distribution<> d(0, 9);
    for (int i = 0; i < N+1; ++i) {
        for (int j = 0; j < N+1; ++j) {
            c[i][j] = d(e);
            std::cout << c[i][j];
            if (j == N) {
                std::cout << std::endl;
            }
            else {
                std::cout << " ";
            }
        }
    }

    /* N=5
        *0000
        **000
        ***00
        ****0
        *****
        ではなく
        *++++
        **+++
        ***++
        ****+
        *****
    */

    // DPテーブル定義
    std::vector<long long> dp(N+1, INF);

    // DP初期条件
    dp[0] = 0;

    // DPループ
    for (int i = 0; i < N+1; ++i) {
        for (int j = 0; j < i; ++j) {
            chmin(dp[i], dp[j] + c[j][i]);
        }
    }

    std::cout << "最小コスト: " << dp[N] << std::endl;
}