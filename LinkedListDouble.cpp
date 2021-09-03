
/*
 * File:   LinkedListDouble.cpp
 * Author: Camilo Cortes
 *
 *
 */

#include "LinkedListDouble.h"
#include<cstdlib>
#include <iostream>

using namespace std;

/**
 * Método que recibe los parámetros de valor Nulo, para ser usados.
 */
template<class T>
LinkedListDouble<T>::LinkedListDouble() {
    head=NULL;
    last=NULL;
}
/**
 * Método que retorna un valor verdadero o falso, dependiendo si la lista tiene
 * o no nodos.
 * @return
 */
template<class T>
bool LinkedListDouble<T>::isEmpty() {
    return head==NULL && last==NULL;
}
/**
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado al inicio.
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addBegin(T info) {
    NodeList<T>* newNode=new NodeList<T>(info);
    if(isEmpty()){
        head=newNode;
        last=newNode;
    }else{
        newNode->next=head;
        head->previous=newNode;
        head=newNode;
    }

}

/**
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado al final.
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addEnd(T info) {
    NodeList<T>* newNode=new NodeList<T>(info);
    if(isEmpty()){
        head=newNode;
        last=newNode;
    }else{
        last->next=newNode;
        newNode->previous=last;
        last=newNode;
    }
}


/**
 * Método que recibe la información de un nodo ya existente.
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado antes del nodo seleccionado.
 * @param node
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addBeforeTo(NodeList<T>* node, T info) {
    NodeList<T>* newNode=new NodeList<T>(info);
    if(node==head){
        head->previous=newNode;
        newNode->next=head;
        head=newNode;
    }else{
        NodeList<T>* aux=head;
        while(aux->next!=node){
            aux=aux->next;
        }
        newNode->next=aux->next;
        aux->next=newNode;
        node->previous=newNode;
        newNode->previous=aux;
    }

}
/**
 * Método que recibe la información de un nodo ya existente.
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado después del nodo seleccionado.
 * @param node
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addAfterTo(NodeList<T>* node, T info) {
    NodeList<T>* newNode=new NodeList<T>(info);
    if(node==last){
        last->next=newNode;
        newNode->previous=last;
        last=newNode;
    }else{
        newNode->next=node->next;
        node->next=newNode;
        newNode->previous=node;
        newNode->next->previous=newNode;
    }
}

/**
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado de manera ordenada.
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addSorted(T info) {
    if(isEmpty()){
        head = new NodeList<T>(info);
    } else {
        NodeList<T>* node = new NodeList<T>(info);
        NodeList<T>* act = head;
        NodeList<T>* ant = NULL;
        while(act != NULL && act->info.getId().compare(info.getId()) < 0){
            ant = act;
            act = act->next;
        }
        if(ant == NULL){
            head = node;
        } else {
            ant->next = node;
            node->previous = ant;
        }
        if(act == NULL){
            last = node;
        } else {
            node->next = act;
            act->previous = node;
        }

    }
}
/**
 * Método que recibe el id del nodo a ser buscado.
 * Método que retorna la información del nodo buscado.
 * @param id
 * @return
 */
template<class T>
NodeList<T>* LinkedListDouble<T>::findNode(string id) {
    NodeList<T>* aux=head;
    while(aux!=NULL){
        if(id.compare(aux->info.getId())==0){
            return aux;
        }
        aux=aux->next;
    }
    return NULL;
}

/**
 * Método que recibe el id del objeto a ser buscado.
 * Método que retorna la información del objeto buscado.
 * @param id
 * @return
 */
template<class T>
T* LinkedListDouble<T>::findInfo(string id) {
    NodeList<T>* aux=head;
    while(aux){
        if(aux->info.getId().compare(id)==0){
            return &aux->info;
        }
    }
    return NULL;
}
/**
 * Método que retorna la posicion de un nodo
 * @return
 */
template<class T>
T* LinkedListDouble<T>::getPos(int pos) {
    int cont=0;
    NodeList<T> * aux= head;
    while (aux!=NULL) {
        cont++;
        if(cont==pos){
            return &aux->info;
        }
        aux= aux->next;
    }
    return NULL;

}
/**
 * Método que retorna el primer nodo de la lista
 * @return
 */
template<class T>
T LinkedListDouble<T>::getFirst() {
    NodeList<T>* aux= head;
    return  aux->info;
}

/**
 * Método que retorna el ultimo nodo de la lista
 * @return
 */
template<class T>
T LinkedListDouble<T>::getEnd() {
    NodeList<T>* aux = last;
    return aux->info;
}

/**
 * Método que recibe un valor booleano donde si encuentra lista con datos,
 * la recorrera hacia adelante.
 * Método que retorna la lista en forma de vector para mostrar la información
 * contenida en esta.
 * @param forward
 * @return
 */
template<class T>
vector<T> LinkedListDouble<T>::getList(bool forward) {
    vector<T> out;
    if(forward){
        NodeList<T>* aux=head;
        while(aux!=NULL){
            out.push_back(aux->info);
            aux=aux->next;
        }
        return out;
    }else{
        NodeList<T>* aux=last;
        while(aux!=NULL){
            out.push_back(aux->info);
            aux=aux->previous;
        }
        return out;
    }

}

/**
 * Método que recibe la información de un nodo existente, eliminara los datos
 * y la posicion de este nodo.
 * Método que retorna la lista menos el nodo que acaba de ser eliminado
 * @param node
 * @return
 */
template<class T>
T LinkedListDouble<T>::deleteNode(NodeList<T>* node) {
    NodeList<T>* delNode= findNode(node->info.getId());

    if(delNode==head){
        head=head->next;
        head->previous=NULL;
    }else if(delNode==last){
        last=last->previous;
        last->next=NULL;
    }else{
        NodeList<T>* aux=head;
        while(aux->next!=delNode){
            aux=aux->next;
        }
        aux->next=delNode->next;
        delNode->next->previous=aux;
    }
    return delNode->info;

}
/**
 * Método que retorna el tamñano total de la lista de nodos
 * @return
 */
template<class T>
int LinkedListDouble<T>::size() {
    return getList(true).size();
}

/**
 * Método Destructor de la clase LinkedListDouble
 *
 */
template<class T>
LinkedListDouble<T>::~LinkedListDouble() {

}


