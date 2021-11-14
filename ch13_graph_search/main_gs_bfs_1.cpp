/**
 * @file main_gs_bfs_1.cpp
 * @author your name (you@domain.com)
 * @brief 幅優先探索-1
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <dirent.h> // mkdir
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// グラフ探索で使用する変数
vector<bool> seen; // 次の探査する候補に頂点vが該当したときseen[v] = true; (※一度trueになるとfalseに戻らない)
//#define DFS // 深さ優先探索
#ifdef DFS
#include <stack>   // 深さ優先探索DFS Depth First-Search 
stack<int> todo;   // 次に探索する頂点候補. 深さ優先探索の場合 stack, 幅優先探索の場合 queue
#else
#include <queue>   // 幅優先探索BFS Breadth First-Search
queue<int> todo;   // 次に探索する頂点候補. 深さ優先探索の場合 stack, 幅優先探索の場合 queue
#endif


// グラフ型 (重みなし)
using Graph = vector<vector<int>>; 


/**
 * @brief グラフ探索過程における、各頂点ｖについてのseenとtodoの状態
 * 
 * 状態                             | seenの状態        | todoの状態
 * ------------------------------------------------------------------------------
 * 探索でまだ未発見                 | seen[v] = false   | vはtodoに含まれていない
 * ------------------------------------------------------------------------------
 * 探索候補だが、未探索             | seen[v] = true    | vはtodoに含まれている
 * ------------------------------------------------------------------------------
 * 探索済み                         | seen[v] = true    | vはtodoに含まれていない
 * ------------------------------------------------------------------------------
 */

// 有効グラフ: G
// 頂点sを始点とする
template <template <typename T, typename Container = std::deque<T, std::allocator<T>>> typename TODO>
void search_graph(const Graph& G, vector<bool>& seen, TODO<int>& todo, int s) {

    int N = (int)G.size(); // グラフの頂点数

    // グラフ探索のためのデータ構造を初期化
    seen.assign(N, false); // 全頂点を「未訪問」に初期化

#ifdef DFS
    // 深さ優先探索の候補を空にする
    while (!todo.empty()) {
        todo.pop();
    }
#else 
    // 幅優先探索の候補を空にする
    while (!todo.empty()) {
        todo.pop();
    }
#endif

    // 始点Sによる初期条件
    seen[s] = true; // Sは探索済みとする
    todo.push(s);   // todoはSのみを含む状態とする

    // 探索
    while (!todo.empty()) {

#ifdef DFS
        // todoから頂点を取り出す
        int v = todo.top();
        todo.pop(); // 末尾を削除
#else
        // todoから頂点を取り出す
        int v = todo.front();
        todo.pop(); // 先頭を削除
#endif

        /*******************************/
        // 探索結果のvに関する処理を記述
        /*******************************/
        cout << v << " :";
        
        // vから辿れる頂点をすべて調べる
        for (int x : G[v]) {
            // 既に発見済みの頂点は探索しない
            if (seen[x]) continue;

            // 新たな頂点xを探索候補として登録
            seen[x] = true;
            todo.push(x);
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}



int main(int, char**) {

    printf("有効グラフ\n");

    // 超点数
    int N = 8;

    // グラフ
    Graph G(N);
    
#ifdef DFS
    // 有効グラフ
    G[0].push_back(5);
    G[1].push_back(3); G[1].push_back(6);
    G[2].push_back(5); G[2].push_back(7);
    G[3].push_back(0); G[3].push_back(7);
    G[4].push_back(1); G[4].push_back(2); G[4].push_back(6);
    // G[5].push_back();
    G[6].push_back(7);
    G[7].push_back(0);
#else
    // 無向グラフ
    G[0].push_back(3); G[0].push_back(5); G[0].push_back(7);
    G[1].push_back(3); G[1].push_back(4); G[1].push_back(6);
    G[2].push_back(4); G[2].push_back(5); G[2].push_back(7);
    G[3].push_back(0); G[3].push_back(1); G[3].push_back(7);
    G[4].push_back(1); G[4].push_back(2); G[4].push_back(6);
    G[5].push_back(0); G[5].push_back(2);
    G[6].push_back(1); G[6].push_back(4); G[6].push_back(7);
    G[7].push_back(0); G[7].push_back(2); G[7].push_back(3); G[7].push_back(6);
#endif

    // 深さ優先探索を実行
    int sv;
    cout << "始点Sを選択してください. "; cin >> sv;
    search_graph(G, seen, todo, sv);

    cout << "OK" << endl;
}