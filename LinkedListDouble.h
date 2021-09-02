

/*
 * File:   LinkedListDouble.h
 * Author: Camilo Cortes
 *
 *
 */

#ifndef LINKEDLISTDOUBLE_HPP
#define LINKEDLISTDOUBLE_HPP
#include "Node.h"
#include <string>
#include <vector>

template<class T>
class LinkedListDouble {
public:
    LinkedListDouble();
    bool isEmpty();
    void addNodeFirst(T);
    void addNodeLast(T);
    void addNodeAfterTo(Node<T>*, T);
    void addNodeBeforeTo(Node<T>*, T);
    void addNodeSorted(T);
    Node<T>* findNode(std::string);
    Node<T>* findInfo(std::string);
    std::vector<T> getLinkedList(bool);
    T deleteNode(Node<T>*);
    int getSize();
    T* getObject(int);
    T getFirst();
    T getLast();

    virtual ~LinkedListDouble();
private:

    Node<T>* head;
    Node<T>* last;

};

#endif /* LINKEDLISTDOUBLE_H */
