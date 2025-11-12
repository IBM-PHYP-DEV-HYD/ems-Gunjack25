#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node {
    T mData;
    Node* mNext;
    Node* mPrev;

    Node() : mData(0), mNext(nullptr), mPrev(nullptr) {}
    Node(T val) : mData(val), mNext(nullptr), mPrev(nullptr) {}
};

#endif
