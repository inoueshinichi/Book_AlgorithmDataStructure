/**
 * @file main_bs_age_quize.cpp
 * @author your name (you@domain.com)
 * @brief 年齢当てクイズ (二分探索法)
 * @version 0.1
 * @date 2021-09-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

int main(int, char**) {
    std::cout << "Start Game!" << std::endl;

    // Aさんの年齢の候補を表す区間[20, 36)
    int left = 20, right = 36;

    // Aさんの年齢を1つに絞れないうちは繰り返す
    while (right - left > 1) {
        int mid = left + (right - left) / 2; // 区間の真ん中

        // mid以上かを聞いて、回答をyes/noで受ける
        std::cout << "Is the age less than " << mid << " ? (yes/no)" << std::endl;
        std::string ans;
        std::cin >> ans;

        // 回答に応じて、ありうる数の範囲を絞る
        if (ans == "yes") right = mid;
        else left = mid;
    }

    // ズバリ当てる
    std::cout << "The age is " << left << "!" << std::endl;
    return 0;
}