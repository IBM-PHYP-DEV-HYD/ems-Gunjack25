#ifndef EDLL_H
#define EDLL_H

#include "Deque.H"

template <typename T>
class EDLL : public Deque<T> {
    public:
        void addElement(size_t indexParm, T& dataParm);
        void removeElementAtIndex(size_t indexParm);
        void removeElement(T& dataParm);
};

template <typename T>
void EDLL<T>::addElement(size_t indexParm, T& dataParm)
{
    if (indexParm > this->size()) {
        std::cout << "Index out of range in addElement()\n";
        return;
    }

    if (indexParm == 0) {
        this->push_front(dataParm);
        return;
    }

    if (indexParm == this->size()) {
        this->push_back(dataParm);
        return;
    }

    Node<T>* itr = this->mHead;
    size_t tmp = 0;

    while (itr != nullptr && tmp < indexParm) {
        itr = itr->mNext;
        tmp++;
    }

    if (itr == nullptr) return; // indexParm overflow safeguard

    Node<T>* newNode = new Node<T>(dataParm);
    Node<T>* prevNode = itr->mPrev;

    newNode->mNext = itr;
    newNode->mPrev = prevNode;

    if (prevNode)
        prevNode->mNext = newNode;

    itr->mPrev = newNode;

    this->mSize++;
}

template <typename T>
void EDLL<T>::removeElementAtIndex(size_t indexParm)
{
        if (this->empty())
    {
        std::cout << "List is empty, cannot remove\n";
        return;
    }

    if (indexParm >= this->size())
    {
        std::cout << "Index out of range in removeElement()\n";
        return;
    }

    if (indexParm == 0)
    {
        this->pop_front();
        return;
    }

    if (indexParm == this->size() - 1)
    {
        this->pop_back();
        return;
    }

    Node<T>* itr = this->mHead;
    size_t tmp = 0;

    while (itr != nullptr && tmp < indexParm)
    {
        itr = itr->mNext;
        tmp++;
    }

    Node<T>* prevNode = itr->mPrev;
    Node<T>* nextNode = itr->mNext;

    if (prevNode != nullptr)
        prevNode->mNext = nextNode;

    if (nextNode != nullptr)
        nextNode->mPrev = prevNode;

    delete itr;
    this->mSize--;
}

template <typename T>
void EDLL<T>::removeElement(T& dataParm)
{
    if (this->empty())
    {
        std::cout << "List is empty\n";
        return;
    }
    else{
        Node<T>* itr = this->mHead;
        size_t indexParm = 0;
        while(itr != nullptr)
        {
            if(itr->mData == dataParm)
            {
                removeElementAtIndex(indexParm);
                return;
            }
            itr = itr->mNext;
            indexParm++;
        }
        std::cout << "Element not found in the list\n";
    }
}

#endif
