/**
 * @file main_recursive_func.cpp
 * @author your name (you@domain.com)
 * @brief 再帰関数
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

// 再帰関数
int func(int N) {
    // 再帰関数を呼び出したことを報告する
    std::printf("func(%d)をよびだしました\n", N);

    if (N == 0) return 0;

    // 再帰的に答えを求めて出力する
    int result = N + func(N - 1);
    std::printf("%dまでの和=%d\n", N, result);

    return result;
}


int main(int argc, char** argv)
{
    int N;
    std::cout << "Input: ";
    std::cin >> N;
    std::cout << "Data size: " << N << std::endl;

    func(N);

    return 0;
}