/**
 * @file main_gsp_floyd_warshall.cpp
 * @author your name (you@domain.com)
 * @brief フロイド・ワーシャル法による全点対間最短路問題(任意の2頂点間の最短路)の解法. O(|V|^3)
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief フロイド・ワーシャル法の特徴
 * ・負辺が含まれていても動作する
 * ・負の閉路が含まれている場合検知できる
 * 
 *  dist[i][j] : 頂点iから頂点jまでの経路
 */

#include <iostream>
#include <vector>
using namespace std;

// 無限大を表す値
const long long INF = 1LL << 60; // 十分大きな値を用いる(ここでは2^60)


void warshall_floyd(vector<vector<long long>>& dist) 
{
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


// 全点対間最短路探索問題の対象グラフ
vector<vector<long long>> dist = {{0, 5, -1, INF},
                                  {INF, 0, INF, 3},
                                  {INF, INF, 0, 1},
                                  {INF, INF, 4, 0}};

int main(int, char**)
{
    int V = (int)dist.size();  // 頂点数
    warshall_floyd(dist);      // 更新


    // 出力. もしdist[v][v]<0なら負閉路が存在する
    bool exist_negative_cycle = false;
    for (int v = 0; v < V; ++v) {
        if (dist[v][v] < 0) exist_negative_cycle = true;
    }

    if (exist_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] >= INF / 2) {
                    cout << "INF";
                } else {
                    cout << dist[i][j];
                }
                if (j != V - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}