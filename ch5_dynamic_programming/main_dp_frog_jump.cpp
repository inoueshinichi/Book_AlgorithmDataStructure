/**
 * @file main_frog_jump.cpp
 * @author your name (you@domain.com)
 * @brief 動的計画法(DP) Frog問題を動的計画法で解く
 * @version 0.1
 * @date 2021-08-28
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
auto chmin = [](auto &a, auto b)
{
    // dp[i]のチャンピオン(最小コスト)をに更新する
    if (a > b)
    {
        a = b;
    }
};

// v3動的計画法の再帰関数
long long recursive_func(int i, std::vector<long long> &dp, std::vector<long long> &h) {
    // dp[i]の最小コストを計算する.

    // // ベースライン
    // if (i == 0) {
    //     return dp[0];
    // }
    // else if (i == 1) {
    //     dp[i] = recursive_func(i - 1, dp, h) + std::abs(h[i] - h[i - 1]);
    //     return dp[i];
    // }

    // long long cost1 = recursive_func(i - 1, dp, h); // dp[i-1]を求める
    // long long cost2 = recursive_func(i - 2, dp, h); // dp[i-2]を求める
    // dp[i] = std::min(cost1 + std::abs(h[i] - h[i - 1]), cost2 + std::abs(h[i] - h[i - 2]));

    // -------------------------------

    // メモ化されている場合、そのままリターン
    if (dp[i] < INF) {
        return dp[i];
    }

    // ベースライン
    if (i == 0) {
        return dp[0];
    }

    // dp[i]をメモ化しながら再帰計算する

    long long cost1 = recursive_func(i - 1, dp, h) + std::abs(h[i] - h[i-1]);
    chmin(dp[i], cost1);

    if (i > 1) {
        long long cost2 = recursive_func(i - 2, dp, h) + std::abs(h[i] - h[i-2]);
        chmin(dp[i], cost2);
    }
    
    return dp[i];
}


int main(int, char**) {

    // 入力
    int N;

    std::printf("飛び移る切り株の数(N)を指定してください\n: ");
    std::cin >> N;

    std::printf("切り株(N個)の高さh_iを指定してください\n");
    std::vector<long long> h(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> h[i];
    }

    // 配列dp(各切り株iに到達する際の最小コスト)を定義.
    // 配列全体を無限大を表す値に初期化
    std::vector<long long> dp(N, INF);

    // 初期条件
    dp[0] = 0;

    // // v0) 各切り株に到達する際の最小コストを計算する
    // {
    //     for (int i = 1; i < N; ++i)
    //     {
    //         if (i == 1)
    //             dp[i] = std::abs(h[i] - h[i - 1]);
    //         else
    //         {
    //             dp[i] = std::min(
    //                 dp[i - 1] + std::abs(h[i] - h[i - 1]) // [i-1]から[i]に飛ぶ
    //                 ,
    //                 dp[i - 2] + std::abs(h[i] - h[i - 2]) // [i-2]から[i]に一個飛ばしで飛ぶ
    //             );
    //         }
    //     }
    // }


    // // v1-[pull base]) 「貰う遷移形式」「緩和」を意識した動的計画法で解く O(N)
    // {
    //     for (int i = 1; i < N; ++i) {
    //         chmin(dp[i], dp[i-1] + std::abs(h[i] - h[i-1]));
    //         if (i > 1) {
    //             chmin(dp[i], dp[i-2] + std::abs(h[i] - h[i-2]));
    //         }
    //     }
    // }

    // // v1-[push base]) 「配る遷移形式」による動的計画法 O(N)
    // {
    //     for (int i = 0; i < N; ++i) {
    //         if (i + 1 < N) {
    //             chmin(dp[i+1], dp[i] + std::abs(h[i] - h[i+1]));
    //         }
    //         if (i + 2 < N) {
    //             chmin(dp[i+2], dp[i] + std::abs(h[i] - h[i+2]));
    //         }
    //     }
    // }

    // v2) 再帰関数で動的計画法を解く
    {
        recursive_func(N - 1, dp, h);
    }

    // 答え
    std::printf("---- Answer ---- \n");
    std::cout << "Minimum cost: " << dp[N - 1] << std::endl;
    std::stringstream ss;
    for (int i = 0; i < dp.size(); ++i) {
        ss << "[" << i <<"]:" << dp[i];
        if (i != dp.size() - 1) {
            ss << ", ";
        }
    }
    std::cout << ss.str() << std::endl;
    return 0;
}