/**
 * @file main_gs_bfs_2.cpp
 * @author your name (you@domain.com)
 * @brief 幅優先探索　最短経路
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// 入力 : グラフG, 探索の開始点S
// 出力 : Sから各頂点への最短経路を表す配列
vector<int> BFS_MinDist(const Graph& G, int s) {
    int N = (int)G.size(); // 頂点数
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化する
    queue<int> que;

    // 初期条件（頂点Sを初期頂点とする）
    dist[s] = 0;
    que.push(s);

    // BFS開始
    while (!que.empty()) {
        int v = que.front();
        que.pop(); // 先頭を削除

        // vから辿れる頂点すべてを調べる
        for (int x : G[v]) {
            if (dist[x] != -1) continue;

            // 新たな頂点xについて距離情報を更新してキューに追加
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }

    return dist;
}

int main(int, char **)
{

    // 超点数
    int N = 8;

    // グラフ
    Graph G(N);

    printf("無効グラフ\n");
    G[0].push_back(3); G[0].push_back(5); G[0].push_back(7);
    G[1].push_back(3); G[1].push_back(4); G[1].push_back(6);
    G[2].push_back(4); G[2].push_back(5); G[2].push_back(7);
    G[3].push_back(0); G[3].push_back(1); G[3].push_back(7);
    G[4].push_back(1); G[4].push_back(2); G[4].push_back(6);
    G[5].push_back(0); G[5].push_back(2);
    G[6].push_back(1); G[6].push_back(4); G[6].push_back(7);
    G[7].push_back(0); G[7].push_back(2); G[7].push_back(3); G[7].push_back(6);

    int sv;
    printf("始点: ");
    cin >> sv;

    // 幅優先探索
    vector<int> dist = BFS_MinDist(G, sv);

    // 出力結果
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}