/**
 * @file main_gsp_belman_ford.cpp
 * @author your name (you@domain.com)
 * @brief ベルマン・フォード法による負閉路を持つグラフに対応した最短経路問題.
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * @brief ベルマン・フォード法
 * 負閉路を持つ可能性のあるグラフに対して
 * 負閉路を持つ場合 -> 通知がある
 * 負閉路を持たない場合 -> 最短経路が求まる
 * 
 * 節数 : V
 * 辺数 : E
 * 
 * 1. 始点sを決める.
 * 2. 各辺に関して一通り緩和する(順序不問)という操作を, 最短経路長推定値d[v]がこうしんされなくなるまで反復する.
 *    for (int iter = 0; iter < N; ++iter) {
 *      for (int v = 0; v < N; ++v) {
 *          // 緩和処理
 *      }
 *    }
 * 
 * 3. 最大でも(V-1)回の反復によってd[v]の値が真の最短経路長d*[v]に収束する.
 *    従って, V回目の反復時にd[v]が更新された場合, グラフ上に始点sから到達できる負閉路が存在する.
 *    ※始点sから到達できない負閉路は不問.
 */

#include <iostream>
#include <vector>
using namespace std;

// 無限大を表す値
const long long INF = 1LL << 60; // 十分大きな値を用いる(ここでは2^60)

// 辺を表す型. ここでは重みを表す型をlong long型とする.
struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

// 重み付き有効グラフ
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template <class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}


int main(int, char**) {

    cout << "負閉路が存在するかもしれないグラフに対するベルマン・フォード法による最短経路計算問題" << endl;

    cout << "グラフ定義" << endl;
    int N = 6; // 頂点数
    int M = 12; // 辺数
    int s; // 始点

    Graph G(N);
    // v=0
    G[0].push_back(Edge(1, 3)); G[0].push_back(Edge(3, 100));
    // v=1
    G[1].push_back(Edge(2, 50)); G[1].push_back(Edge(3, 57)); G[1].push_back(Edge(4, -4));
    // v=2
    G[2].push_back(Edge(3, -10)); G[2].push_back(Edge(4, -5)); G[2].push_back(Edge(5, 100));
    // v=3
    G[3].push_back(Edge(1, -5));
    // v=4
    G[4].push_back(Edge(2, 57)); G[4].push_back(Edge(3, 25)); G[4].push_back(Edge(5, 8));
    // v=5
    // なし

    for (int v = 0; v < N; ++v) {
        cout << v << ": ";
        for (auto e : G[v]) {
            cout << e.to << "(" << e.w << "),";
        }
        cout << endl;
    }

    cout << "-------------------" << endl;
    cout << "始点sを入力してください: ";
    cin >> s;

    // ベルマン・フォード法
    bool exist_negative_cycle = false; // 負閉路をもつかどうか
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) {
        bool update = false; // 更新が発生したかどうかを表すフラグ
        for (int v = 0; v < N; ++v) {
            // dist[v] = INF のときは頂点vからの緩和を行わない
            if (dist[v] == INF) continue;

            for (auto e : G[v]) {
                // 緩和処理を行い, 更新されたらupdateをtrueにする
                if (chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                }
            }
        }

        // 更新がおこなわれなかったら, すでに最短経路が求められている
        if (!update) break;

        // N回目の反復で更新が行われたら, 負閉路を持つ
        if (iter == N - 1 && update) exist_negative_cycle = true;
    }

    // 結果出力
    if (exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int v = 0; v < N; ++v) {
            cout << "Vertex(" << v << ") :";
            if (dist[v] < INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }
}