/**
 * @file main_bs_shoter_problem.cpp
 * @author your name (you@domain.com)
 * @brief 射撃王問題に対する二分探索法
 * @version 0.1
 * @date 2021-10-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> // sort(), lower_bound()
#include <cmath>
#include <random>
#include <numeric>
#include <chrono>
using namespace std::chrono;
using namespace std;
const long long INF = 1LL << 60; // 十分大きな値

int main(int, char**) 
{
    // 入力
    int N;
    std::cout << "Input: ";
    std::cin >> N;
    std::cout << "Data size: " << N << std::endl;


    // N個のデータ(H_i, S_i)を作成
    std::vector<long long> h(N), s(N);
    std::seed_seq seed {20211005};
    std::mt19937_64 engin(seed);
    std::uniform_int_distribution<> height(0, 50); // 高度
    std::uniform_int_distribution<> delta(1, 5);
    for (int i = 0; i < N; ++i) {
        h.at(i) = height(engin);
        s.at(i) = delta(engin);
        std::printf("h[%d]=%d, s[%d]=%d\n", i, h.at(i), i, s.at(i));
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////
    // 各風船を時間内に撃ち落とせる最小の高度xを求める -> 最大値の最小化問題 -> 判定問題に帰着できる
    /////////////////////////////////////////////////////////////////////////////////////////////////
    long long left = 0, right = INF;
    while (right - left > 1) 
    {
        // 比較対象の高度
        long long mid = (right + left) / 2;

        // 判定
        bool ok = true;

        // 比較高度までの残り時間
        std::vector<long long> t(N, 0);

        for (int i = 0; i < N; ++i)
        {
            if (mid < h[i])
                ok = false;
            else
                t[i] = (mid - h[i]) / s[i]; // 残り時間
        }

        std::sort(t.begin(), t.end()); // 残り時間が短い順にソート

        for (int i = 0; i < N; ++i)
        {
            if (t[i] < i) ok = false; // 時間切れ発生
        }

        if (ok) right = mid;
        else left = mid;
    }

    std::cout << "各風船を時間内に撃ち落とせる最小の高度xは, " << right << "です。" << std::endl;
}