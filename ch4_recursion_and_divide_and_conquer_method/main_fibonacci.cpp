/**
 * @file main_fibonacci.cpp
 * @author your name (you@domain.com)
 * @brief フィボナッチ数列 計算量O(((1+√5)/2)^N)@再帰関数, O(N)@forloopによる実装
 * @version 0.1
 * @date 2021-04-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <random>
#include <numeric>
using namespace std::chrono;

// フィボナッチ数列を求める再帰関数
int fibo(int N)
{
    // 再帰関数を呼び出した事を報告する
    std::printf("fibo(%d)を呼び出しました.\n", N);

    // ベースケース
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // 再帰的に答えを求めて出力する
    int result = fibo(N-1) + fibo(N-2);
    std::printf("%d 項目 = %d\n", N, result);

    return result;
}

// フィボナッチ数列を求めるfor_loop
int fibo_for_loop(int N)
{
    std::vector<long long> F(N);
    F[0] = 0, F[1] = 1;
    for (int N = 2; N < 50; ++N)
    {
        F[N] = F[N-1] + F[N-2];
        std::printf("%d 項目 = %lld\n", N, F[N]);
    }
}

int main(int argc, char** argv)
{
    int N;
    std::cout << "Input: ";
    std::cin >> N;
    std::cout << "Data size: " << N << std::endl;

    auto start = high_resolution_clock::now();
    fibo(N);
    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_us = duration_cast<microseconds>(duration).count();
    std::cout << duration_us << "[us]" << std::endl;

    start = high_resolution_clock::now();
    fibo_for_loop(N);
    end = high_resolution_clock::now();
    duration = end - start;
    duration_us = duration_cast<microseconds>(duration).count();
    std::cout << duration_us << "[us]" << std::endl;

    return 0;
}