
/*
 * File:   NodeList.h
 * Author: Camilo Cortes
 *
 */

#ifndef NODELIST_H
#define NODELIST_H
#include <cstdlib>

using namespace std;

template<class T> class LinkedListDouble;

template<class T>
class NodeList {
public:
    friend class LinkedListDouble<T>;

    NodeList();
    NodeList(T info);
    virtual ~NodeList();
private:
    T info;
    NodeList<T>* next;
    NodeList<T>* previous;
};

template<class T>
NodeList<T>::NodeList(){
    next=NULL;
    previous=NULL;
}

template<class T>
NodeList<T>::NodeList(T info){
    this->info=info;
    next=NULL;
    previous=NULL;
}
template<class T>
NodeList<T>::~NodeList(){

}

#endif  //NODELIST_H

