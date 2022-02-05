/**
 * @file main_gsp_dijkstra_1.cpp
 * @author your name (you@domain.com)
 * @brief ダイクストラ法 O(|V|^2) による負の重みを持たない場合の最短経路探索. 蜜なグラフ(|E|≒O(|V|^2))に適用する.
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * @brief ダイクストラ法
 * 負の重みを持たない場合, 最短経路値(d[v])を動的に更新していく過程で自動的に緩和を行うべき
 * 頂点順序が決まる.
 * → 「すでに最短路が求められていることが確定している頂点集合S」を管理することで実現できる.
 * 初期値: d[s] = 0, S = {s}
 * 更新: 頂点数N回の各反復において「まだSに含まれていない頂点vのうち, d[v]の値が最小の頂点」は, 
 * 　　　最短経路値d[v]*に収束しているので, 頂点vを新たに集合Sに挿入し, 頂点vを始点とする各辺について
 *       緩和を行う.
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


int main(int, char**) 
{
    cout << "非負重みしか存在しないグラフに対する最短経路計算問題はダイクストラ法で解く" << endl;

    cout << "グラフ定義" << endl;
    int N = 6; // 頂点数
    int M = 12; // 辺数
    int s; // 始点

    Graph G(N);
    // v=0
    G[0].push_back(Edge(1, 3)); G[0].push_back(Edge(2, 5));
    // v=1
    G[1].push_back(Edge(2, 4)); G[1].push_back(Edge(3, 12));
    // v=2
    G[2].push_back(Edge(3, 9)); G[2].push_back(Edge(4, 4));
    // v=3
    G[3].push_back(Edge(5, 2));
    // v=4
    G[4].push_back(Edge(3, 7)); G[4].push_back(Edge(5, 8));
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

    // ダイクストラ法
    vector<bool> used(N, false); // 集合S
    vector<long long> dist(N, INF); // 経路値
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) // 頂点数N回の反復
    {
        // 「使用済み」でない頂点のうち, dist値が最小の頂点を探す
        long long min_dist = INF;
        int min_v = -1;
        for (int v = 0; v < N; ++v)
        {
            if (!used[v] && dist[v] < min_dist)
            {
                min_dist = dist[v];
                min_v = v;
            }
        }

        // もしそのような頂点がみつからなければ終了する
        if (min_v == -1) break;

        // min_vを始点とした各辺を緩和する
        for (auto e : G[min_v])
        {
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true; // min_vを「使用済み」とする
    }

    // 出力結果
    for (int v = 0; v < N; ++v) 
    {
        cout << "Vertex(" << v << ") :";
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}