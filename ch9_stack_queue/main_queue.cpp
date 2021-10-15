/**
 * @file main_queue.cpp
 * @author your name (you@domain.com)
 * @brief リングバッファによるキュー実装
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // キュー配列の最大サイズ

int qu[MAX];
int tail = 0, head = 0;


void init() {
    head = tail = 0;
}

bool isEmpty() {
    return (head == tail);
}

bool isFull() {
    return (head == (tail + 1) % MAX);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "error: queue is full." << endl;
        return;
    }
    qu[tail] = x;
    ++tail;
    if (tail == MAX) tail = 0;
}

int dequeue() {
    if (isEmpty()) {
        cout << "error: queue is empty." << endl;
        return -1;
    }
    int res = qu[head];
    ++head;
    if (head == MAX) head = 0;
    return res;
}


int main(int, char**) {
    init();

    enqueue(3); // {} -> {3}
    enqueue(5); // {3} -> {3,5}
    enqueue(7); // {3,5} -> {3,5,7}

    cout << dequeue() << endl; // {3,5,7} -> {5,7}
    cout << dequeue() << endl; // {5,7} -> {7}

    enqueue(9); // {7} -> {7,9}
    
    return 0;
}