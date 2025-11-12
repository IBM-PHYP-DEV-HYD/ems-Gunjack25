#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include "Node.H"

#define REVERSE -1 
#define FORWARD 1

template <typename T>
class Deque {
    protected:
        Node<T>* mHead;
        Node<T>* mLast;
        size_t mSize;

    public:
        Deque();
        Deque(size_t sUserSizeParam, T valParam);
        virtual ~Deque();

        void push_back(T valParam);
        void pop_back();

        void push_front(T valParam);
        void pop_front();

        T front();
        T back();
        size_t size();
        bool empty();
        void resize(size_t sUserSizeParam, T valParam, int directionParam = REVERSE);
        T at(size_t sIndexParam);

        void print();
        void clear();
        friend std::ostream& operator<<(std::ostream& os, const Deque<T>& objParam); 
        T operator[](size_t sIndexParam);
};

template <typename T>
Deque<T>::Deque() : mHead(nullptr), mLast(nullptr), mSize(0) {}

template <typename T>
Deque<T>::Deque(size_t sUserSizeParam, T valParam) : mHead(nullptr), mLast(nullptr), mSize(0)
{
    resize(sUserSizeParam, valParam);
}

template <typename T>
Deque<T>::~Deque() {
    clear();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& sDequeObjParam) 
{
    Node<T>* sCurrNode = sDequeObjParam.mHead;
    while (sCurrNode != nullptr) {
        os << sCurrNode->mData << " ";
        sCurrNode = sCurrNode->mNext;
        }
    return os;
}

template <typename T>
void Deque<T>::clear() {
    Node<T>* sIterator = mHead;
    while(sIterator != nullptr)
    {
        Node<T>* sTempNode = sIterator->mNext;   
        delete sIterator;
        sIterator = sTempNode;
    }
    mHead = nullptr;
    mLast = nullptr;
    mSize = 0;
}

template <typename T>
void Deque<T>::print() {
    Node<T>* sIterator = mHead;
    while(sIterator != nullptr)
    {
        std::cout << sIterator->mData << "\n";
        sIterator = sIterator->mNext;   
    } 
}

template <typename T>
void Deque<T>::push_back(T valParam)
{
    Node<T>* sTempNode = new Node(valParam);
    if(mLast != nullptr)
    {
        mLast->mNext = sTempNode;
        sTempNode->mPrev = mLast;
        mLast = sTempNode;
    }
    else
    {
        mHead = sTempNode;
        mLast = sTempNode;
    }
    mSize++;
}

template <typename T>
void Deque<T>::pop_back()
{
    if(nullptr == mLast)
        return;
    if(nullptr == mLast->mPrev)
    {
        delete mLast;
        mLast = mHead = nullptr;
        mSize = 0;
        return;
    }
    Node<T>* sPrevLast = mLast->mPrev;
    sPrevLast->mNext = nullptr;
    Node<T>* sTempNode = mLast;
    mLast = sPrevLast;
    delete sTempNode;
    mSize--;
}

template <typename T>
void Deque<T>::push_front(T valParam)
{
    Node<T>* sTempNode = new Node(valParam);
    if(mHead != nullptr)
    {
        mHead->mPrev = sTempNode;
        sTempNode->mNext = mHead;
        mHead = mHead->mPrev;
    }
    else{
        mHead = mLast = sTempNode;
    }
    mSize++;
}

template <typename T>
void Deque<T>::pop_front()
{
    if(nullptr == mHead)
        return;
    if(nullptr == mHead->mNext)
    {
        delete mHead;
        mLast = mHead = nullptr;
        mSize = 0;
        return;
    }
    Node<T>* sNextHead = mHead->mNext;
    sNextHead->mPrev = nullptr;
    Node<T>* sTempNode = mHead;
    mHead = sNextHead;
    delete sTempNode;
    mSize--;
}

template <typename T>
T Deque<T>::front()
{
    if(nullptr == mHead)
        return T{};
    return mHead->mData;
}

template <typename T>
T Deque<T>::back()
{
    if(nullptr == mLast)
        return T{};
    return mLast->mData;
}

template <typename T>
size_t Deque<T>::size()
{
    return mSize;
}

template <typename T>
bool Deque<T>::empty()
{
    return !mSize;
}

template <typename T>
T Deque<T>::at(size_t indexParam)
{
    Node<T>* sIterator = mHead;
    size_t sInit = 0;
    while(sIterator != nullptr && sInit != indexParam)
    {
        sIterator = sIterator->mNext;
        sInit++;    
    }
    if(sIterator != nullptr)
        return sIterator->mData;

    return T{}; 
}

template <typename T>
T Deque<T>::operator[](size_t sIndex)
{
    return at(sIndex);
}

template <typename T>
void Deque<T>::resize(size_t sUserSizeParam, T valParam, int sDirectionParam)
{
    size_t sPrevSize = mSize;
    int sNewSize = sUserSizeParam - sPrevSize;
    if(sNewSize < 0)
    {
        clear();
        sNewSize = sUserSizeParam; 
    }

    if(sDirectionParam == REVERSE)
    {
        for(size_t sIterator=0; sIterator<sNewSize; sIterator++)
        {
            push_back(valParam);
        }
    }
    else{
        for(size_t sIterator=0; sIterator<sNewSize ; sIterator++)
        {
            push_front(valParam);
        }
    } 
}



#endif