/**
 * @file main_ga_interval_schedule.cpp
 * @author your name (you@domain.com)
 * @brief 貪欲法　区間スケジューリング　パターン1) 交換しても悪化しない
 * @version 0.1
 * @date 2021-10-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <sstream>
using namespace std;

// 区間を表すpair<int,int>
using Interval = pair<int,int>;

// 区間を終端時刻で大小比較する関数
bool cmp(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}


int main(int, char**)
{
    // 入力
    std::printf("区間数Nを指定してください ");
    int N; cin >> N;
    vector<Interval> inter(N);
    for (int i = 0; i < N; ++i)
    {
        printf("区間%dを決めてください\n", i);
        cout << "first "; cin >> inter[i].first;
        cout << "second "; cin >> inter[i].second;
    }

    // 終端時刻が早い順にソート
    sort(inter.begin(), inter.end());

    // 貪欲に選ぶ
    int res = 0;
    int current_end_time = 0;
    ostringstream oss; oss << "選択した区間: ";
    for (int i = 0; i < N; ++i)
    {
        // 最後に選んだ区間と被るのは除く
        if (inter[i].first < current_end_time) continue;
        oss << i << " ";

        ++res;
        current_end_time = inter[i].second;
    }
    oss << endl;
    cout << res << endl;
    cout << oss.str() << endl;
}