
/*
 * File:   LinkedListDouble.cpp
 * Author: Camilo Cortes
 *
 *
 */

#include "LinkedListDouble.h"

/**
 * Método que recibe los parámetros de valor Nulo, para ser usados.
 */
template<class T>
LinkedListDouble<T>::LinkedListDouble() {
    head = NULL;
    last = NULL;
}

/**
 * Método que retorna un valor verdadero o falso, dependiendo si la lista tiene
 * o no nodos.
 * @return
 */
template<class T>
bool LinkedListDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

/**
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado al inicio.
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addNodeFirst(T info) {
    Node<T>* node = new Node<T>(info);

    if(isEmpty()) {
        head = node;
        last = node;
    } else {
        node->next = head;
        head->previous = node;
        head = node;
    }
}

/**
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado al final.
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addNodeLast(T info) {
    Node<T>* node = new Node<T>(info);

    if(isEmpty()) {
        head = last;
        last = node;
    } else {
        last->next = node;
        node->previous = last;
        last = node;
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
void LinkedListDouble<T>::addNodeAfterTo(Node<T>* node, T info) {
    Node<T>* nNode = new Node<T>(info);

    if(last == node) {
        last->next = nNode;
        nNode->previous = last;
        last = nNode;
    } else {
        nNode->next = node->next;
        node->next = nNode;
        nNode->next->previous = nNode;
        nNode->previous = node;
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
void LinkedListDouble<T>::addNodeBeforeTo(Node<T>* node, T info) {
    Node<T>* nNode = new Node<T>(info);
    nNode->next = node;

    if(node == head) {
        head = nNode;
    } else {
        Node<T>* aux = head;

        while(aux->next != node) {
            aux = aux->next;
        }
        aux->next = nNode;
    }
}

/**
 * Método que recibe un parámetro donde contiene la información completa del
 * nodo que será agregado de manera ordenada.
 * @param info
 */
template<class T>
void LinkedListDouble<T>::addNodeSorted(T info) {
    Node<T>* newnode=new Node<T>(info);
    if(isEmpty()){
        head=last=newnode;
    }else{
        Node<T>* aux=head;
        Node<T>* anterior=NULL;
        while(aux!=NULL && aux->info.getId().compare(info.getId())<0){
            anterior=aux;
            aux=aux->next;
        }
        if(anterior==NULL){
            head=newnode;
            newnode->next=aux;
            aux->previous=newnode;
        }else{
            if(aux==NULL){
                last=newnode;
                newnode->previous=anterior;
                anterior->next=newnode;
            }else{
                anterior->next=newnode;
                aux->previous=newnode;
                newnode->previous=anterior;
                newnode->next=aux;
            }
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
Node<T>* LinkedListDouble<T>::findNode(std::string id) {
    Node<T>* aux = head;

    while(aux != NULL) {
        if(aux->info.getId().compare(id) == 0) {
            return aux;
        }
        aux = aux->next;
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
Node<T>* LinkedListDouble<T>::findInfo(std::string id) {
    Node<T>* aux = head;

    while(aux != NULL) {
        if(aux->info.getId().compare(id) == 0) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
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
std::vector<T> LinkedListDouble<T>::getLinkedList(bool forward) {
    std::vector<T> out;
    Node<T>* it = forward ? head : last;

    while(it != NULL) {
        out.push_back(it->info);
        it = forward ? it->next : it->previous;
    }
    return out;
}

/**
 * Método que recibe la información de un nodo existente, eliminara los datos
 * y la posicion de este nodo.
 * Método que retorna la lista menos el nodo que acaba de ser eliminado
 * @param node
 * @return
 */
template<class T>
T LinkedListDouble<T>::deleteNode(Node<T>* node) {
    Node<T>* aux = node;

    if(node == head) {
        head = head->next;
    } else {
        Node<T>* actually = head;

        while(actually->next != node) {
            actually = actually->next;
        }
        actually->next = node->next;
    }
    delete(node);

    return aux->info;
}

/**
 * Método que retorna el tamñano total de la lista de nodos
 * @return
 */
template<class T>
int LinkedListDouble<T>::getSize() {
    Node<T>* aux = head;
    int cont = 0;

    while(aux != NULL) {
        aux = aux->next;
        cont++;
    }
    return cont-1;
}

/**
 * Método que recibe el valor de la posición del objeto que se quiere obtener.
 * Método que retorna la información del objeto buscado.
 * @param pos
 * @return
 */
template<class T>
T* LinkedListDouble<T>::getObject(int pos) {
    Node<T>* aux = head;
    int cont = 1;

    while(cont != pos) {
        aux = aux->next;
    }
    return &aux;
}

/**
 * Método que retorna el primer nodo de la lista
 * @return
 */
template<class T>
T LinkedListDouble<T>::getFirst() {
    return head->info;
}

/**
 * Método que retorna el ultimo nodo de la lista
 * @return
 */
template<class T>
T LinkedListDouble<T>::getLast() {
    return last->info;
}

template<class T>
LinkedListDouble<T>::~LinkedListDouble() {

}
