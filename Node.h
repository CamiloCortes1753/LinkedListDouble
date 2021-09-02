
/*
 * File:   Node.hpp
 * Author: Camilo Cortes
 *
 *
 */

#ifndef NODE_H
#define NODE_H
#include <cstdlib>

template<class T> class LinkedListDouble;

template<class T>
class Node {
    friend class LinkedListDouble<T>;
public:
    Node();
    Node(T);

    virtual ~Node();
private:

    T info;
    Node<T>* next;
    Node<T>* previous;

};

template<class T>
Node<T>::Node() {
    next = NULL;
    previous = NULL;
}

template<class T>
Node<T>::Node(T info) {
    this->info = info;
    next = NULL;
    previous = NULL;
}

template<class T>
Node<T>::~Node() {

}

#endif /* NODE_H */

