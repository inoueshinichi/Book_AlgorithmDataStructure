/**
 * @file main_networkflow_fordfulkerson.cpp
 * @author your name (you@domain.com)
 * @brief ネットワークフロー問題: フォード・ファルカーソン法
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// グラフを表す構造体
struct Graph 
{
    // 辺を表す構造体
    // rev: 逆辺(to, from)がG[to]の中で何番目の要素か
    // cap: 辺(from, to)の容量
    struct Edge 
    {
        int rev;
        int from, to;
        int cap;
        Edge(int rev, int from, int to, int cap)
            : rev(rev), from(from), to(to), cap(cap) {}
    };

    // 隣接リスト
    vector<vector<Edge>> list;

    // N: 頂点数
    Graph(int N = 0) : list(N) {}

    // グラフの頂点数を取得
    size_t size() { return list.size(); }

    // GraphインスタンスをGとしてG.list[v]をG[v]と書けるようにする
    vector<Edge>& operator[](int n) { return list[n]; }

    // 辺e=(u,v)の逆辺(v,u)を取得する
    Edge& redge(const Edge& e) { return list[e.to][e.rev]; }

    // 辺e=(u,v)に流量fのフローを流す
    // e=(u,v)の流量がfだけ減少する.
    // このとき逆辺(v,u)の流量を増やす
    void run_flow(Edge& e, int f) 
    {
        e.cap -= f;
        redge(e).cap += f;
    }

    // 頂点fromから頂点toへ容量capの辺を張る.
    // このときtoからfromへも容量0の辺を張っておく.
    void add_edge(int from, int to, int cap) 
    {
        int rev_from = (int)list[from].size(); // e=(to,from)のrev
        int rev_to = (int)list[to].size();     // e=(from,to)のrev
        list[from].push_back(Edge(rev_to, from, to, cap));
        list[to].push_back(Edge(rev_from, to, from, 0));
    }
};



struct FordFulkerson
{
    static const int INF = 1 << 30; // 無限大を表す値を適切に
    vector<int> seen; // 訪問済み集合Sを管理. 訪問済みならtrue

    // 残余グラフ上でs-tパスを見つける(深さ優先探索)
    // 戻り値はs-tパス上の容量の最小値. 見つからなかったら0
    // f: sからvへ到達した過程の各辺の容量の最小値
    // v: 再帰関数としての初期値は始点s
    int fodfs(Graph& G, int v, int t, int f)
    {
        // 終端tに達したらリターン
        if (v == t) return f;

        // 深さ優先探索
        seen[v] = true;
        for (auto& e : G[v])
        {
            if (seen[e.to]) continue; // 訪問済みならスキップ

            if (e.cap == 0) continue; // 容量0の辺は実際に存在しないので無視

            // s-tパスを探す
            // 見つかったらflowはパス上の最小容量
            // 見つからなかったら f = 0
            int flow = fodfs(G, e.to, t, min(e.cap, f));

            // s-tパスが見つからなかったら次辺を試す.
            if (flow == 0) continue;

            // 辺eに容量flowのフローを流す
            G.run_flow(e, flow);

            // s-tパスを見つけたらパス上の最小容量を返す
            return flow;
        }

        // s-tパスが見つからなかった事を示す
        return 0;
    }


    // グラフGのs-t間の最大流量を求める
    // ただし、リターン時にGは残余グラフになる
    int solve(Graph& G, int s, int t)
    {
        int res = 0;

        // 残余グラフにs-tパスがなくなるまで反復
        while (true)
        {
            seen.assign((int)G.size(), 0); // 未訪問状態にする
            int flow = fodfs(G, s, t, INF);

            // s-tパスが見つからなかったら終了
            if (flow == 0) return res;

            // 答えを加算
            res += flow;
        }

        // no reach
        return 0;
    }
};


int main(int, char**)
{
    cout << "フォード・ファルカーソン法でネットワークの最大流量問題を解く" << endl;

    cout << "グラフ定義" << endl;
    int N = 6; // 頂点数
    int M = 9; // 辺数
   

    Graph G(N);
    // v=0
    G.add_edge(0, 1, 5); G.add_edge(0, 3, 5);
    // v=1
    G.add_edge(1, 2, 4); G.add_edge(1, 3, 37);
    // v=2
    G.add_edge(2, 4, 56); G.add_edge(2, 5, 9);
    // v=3
    G.add_edge(3, 2, 3); G.add_edge(3, 4, 9);
    // v=4
    G.add_edge(4, 5, 2);
    // v=5
    // なし

    for (int v = 0; v < N; ++v) {
        for (auto e : G[v]) {
            cout << "e=(" << e.from << "," << e.to << "): " << e.cap << endl;
        }
    }


    int s, t;
    cout << "-------------------" << endl;
    cout << "始点sを入力してください: ";
    cin >> s; 
    cout << "終点tを入力してください: ";
    cin >> t;

    // フォード・ファルカーソン法
    FordFulkerson ff;
    printf("始点 %d から終点 %d までの最大フローは %d です.\n", s, t, ff.solve(G, s, t));
}