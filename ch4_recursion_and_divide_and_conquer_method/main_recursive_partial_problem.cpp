/**
 * @file main_recursive_partial_problem.cpp
 * @author your name (you@domain.com)
 * @brief 再帰関数による部分和問題の解放 O(2^N)
 * @version 0.1
 * @date 2021-08-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////
// N個{a_0, a_1, a_2, a_3, ..., a_N-1}から任意の個数を選んで
// 部分集合(0 ~ 2^N)のうち、一つを作り、その総和がWであるか否か
// を判断する問題
// 1. -> a_N-1を選ばずに、残り{a_0, a_1, ..., a_N-2}からの任意個数の和が(W)となる
// 2. -> a_N-1を選んで、残り{a_0, a_1, ..., a_N-2}からの任意個数の和が(W-a_N-1)となる
// 大元の問題は(1), (2)の小問題分割できる.
/////////////////////////////////////////////////////////
int basecase_count = 0;

// {a_0, a_1, ..., a_N-1}のうち最初のi個{a_0, a_1, ..., a_i-1}から
// 何個か選んで総和を(W)にできるかどうかをboolで返す再帰関数
bool func(int i, int w, const vector<int> &a) {
    // ベースケース
    if (i == 0) {
        basecase_count += 1;
        if (w == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    // a[i-1]を選ばない場合
    if (func(i - 1, w, a)) {
        return true;
    }

    // a[i-1]を選ぶ場合
    if (func(i - 1, w - a[i - 1], a)) {
        return true;
    }

    // 
    return false;
}


int main(int, char**) {

    // 入力
    int N, W;
    std::printf("集合の要素数(N)を指定してください. \n");
    std::printf(":");
    cin >> N;
    std::printf("総和数(W)を指定してください. \n");
    std::printf(":");
    cin >> W;
    
    std::printf("%d個だけ要素を指定してください.\n", W);
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    std::printf("---- Problem ---- \n");
    stringstream ss;
    ss << "(";
    for (int i = 0; i < a.size(); ++i) {
        ss << a[i];

        if (i != a.size() - 1) {
            ss << ",";
        }
    }
    ss << "), W=" << W;
    cout << ss.str() << endl;

    std::printf("---- Answer ---- \n");

    // 再帰的に解く
    if (func(N, W, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    // ベースケースの呼び出し回数
    cout << basecase_count << endl;

    return 0;
}