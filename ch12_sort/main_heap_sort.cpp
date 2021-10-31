/**
 * @file main_heap_sort.cpp
 * @author your name (you@domain.com)
 * @brief ヒープソート min O(NlogN) max O(NlogN) In-Place, No-stable
 * @version 0.1
 * @date 2021-10-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;


// i番目の頂点を根とする部分木において、ヒープ条件を満たすようにする
// aのうち0番目からN-1番目までの部分a[0:N]についてのみ考える
void Heapify(vector<int>& a, int i, int N) {
    int child1 = i * 2 + 1; // 左の子供
    if (child1 >= N) return; // 子供がいない場合は終了

    // 子供同士を比較
    if (child1 + 1 < N && a[child1 + 1] > a[child1]) child1++;

    // i: 親, 2*i+1: 左の子供, 2*i+2: 右の子供
    if (a[child1] <= a[i]) return; // 逆転がなかったら終了

    swap(a[i], a[child1]);

    // 再帰的に
    Heapify(a, child1, N);
}


// 配列aをソートする
void HeapSort(vector<int>& a) {
    int N = (int)a.size();

    // Step1: a全体をヒープにするフェーズ
    for (int i = N / 2 - 1; i >= 0; --i) {
        Heapify(a, i, N);
    }

    // Step2: ヒープから1個づつ最大値をpopするフェーズ
    for (int i = N - 1; i > 0; --i) {
        swap(a[0], a[i]); // ヒープの最大値を左づめ
        Heapify(a, 0, i); // ヒープサイズはiに
    }
}


void showArray(vector<int>& a) {
    ostringstream oss;
    for (int i = 0; i < (int)a.size(); ++i) {
        oss << a[i] << " ";
    }
    cout << oss.str() << endl;
}


int main(int, char**) {

    // 入力
    int N;
    cout << "要素数を入力してください ";
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    showArray(a);
    cout << "--------" << endl;

    // ヒープソート
    HeapSort(a);
    showArray(a);
}