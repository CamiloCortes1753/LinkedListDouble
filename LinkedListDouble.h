
/*
 * File:   LinkedListDouble.hpp
 * Author: Camilo Cortes
 *
 *
 */

#ifndef LINKEDLISTDOUBLE_H
#define LINKEDLISTDOUBLE_H
#include "NodeList.h"
#include <vector>
#include <string>

using namespace std;

template<class T>
class LinkedListDouble {
public:

    LinkedListDouble();
    bool isEmpty();
    void addBegin(T info);
    void addEnd(T info);
    void addAfterTo(NodeList<T>* node, T info);
    void addBeforeTo(NodeList<T>* node, T info);
    void addSorted(T info);
    T* getPos(int pos);
    T getFirst();
    T getEnd();
    int size();
    NodeList<T>* findNode(string id);
    T* findInfo(string id);
    T deleteNode(NodeList<T>* node);
    vector<T> getList(bool forward);
    virtual ~LinkedListDouble();

private:
    NodeList<T>* head;
    NodeList<T>* last;
};

#endif  //LINKEDLISTDOUBLE_H

