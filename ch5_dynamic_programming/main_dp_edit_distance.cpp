/**
 * @file main_dp_edit_distance.cpp
 * @author your name (you@domain.com)
 * @brief 動的計画法　編集距離 = ２つの文字列S,Tの類似度を測るもの
 * @version 0.1
 * @date 2021-10-01
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

template <typename T>
void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const int INF = 1 << 29; // 十分大きな値(2^29)


// 1. 変更操作(Sのi文字目とTのj文字目とを対応させる)
// S[i-1] == T[j-1] -> chmin(dp[i][j], dp[i-1][j-1])
// S[i-1] != T[j-1] -> chmin(dp[i][j], dp[i-1][j-1] + 1)

// 2. 削除操作(Sのi文字目を削除) chmin(dp[i][j], dp[i-1][j] + 1)

// 3. 挿入操作(Tのj文字目を削除 == Sの好きな箇所に1文字挿入する) chmin(dp[i][j], dp[i][j-1] + 1)

int main(int, char**) {

    // 入力
    std::string S, T;
    std::printf("文字列Sを入力してください\n");
    std::cin >> S;
    std::printf("文字列Tを入力してください\n");
    std::cin >> T;

    // DPテーブル
    std::vector<std::vector<int>> dp(S.size()+1, std::vector<int>(T.size()+1, INF));

    // DP 初期条件
    dp[0][0] = 0;

    // DP ループ
    for (int i = 0; i <= S.size(); ++i) {
        for (int j = 0; j <= T.size(); ++j) {

            // 変更条件
            if (i > 0 && j > 0) {
                if (S[i-1] == T[j-1]) {
                    chmin(dp[i][j], dp[i-1][j-1]);
                }
                else {
                    chmin(dp[i][j], dp[i-1][j-1] + 1);
                }
            }

            // 削除操作
            if (i > 0) chmin(dp[i][j], dp[i-1][j] + 1);

            // 挿入操作
            if (j > 0) chmin(dp[i][j], dp[i][j-1] + 1);
        }
    }

    // 答えの出力
    std::printf("編集距離は%dです.\n", dp[S.size()][T.size()]);
    return 0;
}