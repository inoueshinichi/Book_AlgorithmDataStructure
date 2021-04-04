/**
 * @file main_partial_sum_problem.cpp
 * @author your name (you@domain.com)
 * @brief 部分和問題
 * @version 0.1
 * @date 2021-04-04
 * 
 * @copyright Copyright (c) 2021
 * 
 * 部分和問題
 * N個の正の整数a_0,a_1,...,a_N-1と正の整数Wが与えられたとき、
 * a_0,a_1,...,a_N-1の中から何個か整数を選んで総和Wを作ることができるか判定する。
 * 
 * N個の整数の部分和は2^N通りある
 * N=3のとき、
 * 空集合Φ, {a_0}, {a_1}, {a_2}, {a_0,a_1}, {a_0,a_2}, {a_1,a_2}, {a_0,a_1,a_2}
 * -> 整数の二進法表現とビット演算で表現可能
 * 
 * 二進法表現でN桁以下となる整数は、通常の十進法で表すと0以上2^N未満の値となる.
 * 
 * 部分集合 | 二進法での値 | 十進法での値
 * Φ         |000|0         
 * {a0}      |001|1
 * {a1}      |010|2
 * {a0,a1}   |011|3
 * {a2}      |100|4
 * {a0,a2}   |101|5
 * {a1,a2}   |110|6
 * {a0,a1,a2}|111|7
 */

/**
 * @brief 0以上2^N未満の整数値bitが与えられたとき、それに対応する部分集合を復元する方法
 * 方針：各i=0,1,...,N-1に対して、整数bitの表す部分集合にi番目の要素aiが含まれるかどうかを判定する.
 * -> 整数bitを二進法表現で表したときに, bitのi桁目が1になっているかどうかで判定する.
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <random>
#include <numeric>
using namespace std::chrono;


int main(int argc, char** argv)
{
    int N, W;
    std::cout << "Input: ";
    std::cout << "N:";
    std::cin >> N;
    std::cout << "W:";
    std::cin >> W;
    std::printf("N:%d, W:%d\n", N, W);

    // a[i]を用意する
    std::seed_seq seed {20210320};
    std::mt19937_64 engin(seed);
    std::uniform_int_distribution<> dist(0, N);
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) 
    {
        a[i] = dist(engin);
        std::printf("a[%d]=%d\n", i, a.at(i));
    }

    auto start = high_resolution_clock::now();

    // bitは2^N通りの部分集合全体を動く: a_0, a_1,..., a_N-1 から何個か取り出して部分集合を作るパターンを網羅する
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        int sum = 0; // 部分集合に含まれる要素の和
        for (int i = 0; i < N; ++i)
        {
            // bitの表す部分集合にi番目の要素が含まれる場合
            if (bit & (1 << i))
            {
                sum += a[i];
            }
            // 含まれない場合
            {
                // nothing
            }
        }

        // sumがWに一致するかどうか
        if (sum == W) exist = true;
    }
    
    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_us = duration_cast<microseconds>(duration).count();
    std::cout << duration_us << "[us]" << std::endl;

    if (exist) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}