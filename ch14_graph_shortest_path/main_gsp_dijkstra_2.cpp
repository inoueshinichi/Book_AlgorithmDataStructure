/**
 * @file main_gsp_dijkstra_2.cpp
 * @author your name (you@domain.com)
 * @brief ダイクストラ法 O(|E|log|V|) による負の重みを持たない場合の最短経路探索.
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * @brief ダイクストラ法の高速化を目指す部分
 * 使用済みでない頂点vのうち, d[v]の値が最小の頂点を求める部分. (従来は線形探索O(|V|)だった)
 * 
 * 使用済みでない頂点vの集合をヒープで実現することで高速化が可能.
 * ヒープ要素
 * ・使用済みでない頂点v
 * ・その頂点vにおけるd[v]
 * ※キー値をd[v]とする.
 * ※通常, ヒープはキー値最大の要素を取得するが, ここでは最小の要素を取得するように変更する.
 * 
 * d[v]の値を変更する処理について工夫がある.
 * 通常の方法: ヒープ機能を拡張して特定の要素にランダムアクセスできる状態にして, そのキー値を変更出来るようにする方法. 
 * →実装が大変.
 * そこで, ヒープのd[v]の値を変更する代わりに, 変更後のd[v]をもつ(d[v], v)の組を新たにヒープに追加する.
 * その場合, (d[v]_1, v), (d[v]_2, v)の頂点vに対して異なる複数要素の組が存在することになるが, ヒープから取り出される
 * キー値は, 必ず最小のd[v]となるので, 片方のゴミ要素は, ヒープ内で放置してよい.
 * また, ゴミが増えても計算量は増大しない. 詳しくは書籍を読め!
 */
#include <iostream>
#include <vector>
#include <queue> // ヒープ
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
    cout << "非負重みしか存在しないグラフに対する最短経路計算問題はダイクストラ法で解く(ヒープバージョン)" << endl;

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

    // (d[v], v)のペアを要素としたヒープをつくる
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
    que.push(make_pair(dist[s], s));

    // ダイクストラ法の反復を開始
    while (!que.empty())
    {
        // v: 使用済みでない頂点のうちd[v]が最小の頂点
        // d: vに対するキー値
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        // d > dist[v]は, (d, v)がゴミ要素であることを意味するのでスキップ
        if (d > dist[v]) continue;

        // 頂点vを始点とした各辺を緩和
        for (auto e : G[v])
        {
            if (chmin(dist[e.to], dist[v] + e.w))
            {
                // 更新があるならヒープに新たに挿入(既存を更新でない)
                que.push(make_pair(dist[e.to], e.to)); // 内部でヒープの構成が変わる
            }
        }
    }

    // 出力結果
    for (int v = 0; v < N; ++v) 
    {
        cout << "Vertex(" << v << ") :";
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
