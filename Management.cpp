
/*
 * File:   Management.cpp
 * Author: Camilo Cortes
 *
 *
 */

#include "Management.h"
#include "LinkedListDouble.cpp"
#include <cstdlib>
#include <string>


LinkedListDouble<Computer>* list;


using namespace std;
/**
 * Método que crea un objeto de tipo linkedListDouble.
 *
 */
Management::Management() {
    list = new LinkedListDouble<Computer>();
}

/**
 * Método que retorna un valor verdadero o falso, validando si la lista tiene nodos o no.
 * @return
 */
bool Management::isEmpty() {
    list->isEmpty();
}
/**
 * Método que recibe el id del Objeto a ser buscado.
 * Método que retorna la información del Obejto.
 * @param id
 * @return
 */
Computer* Management::findComputer(string id) {
    for (int i = 0; i < computers.size(); i++) {
        if (computers.at(i).getId().compare(id) == 0) {
            return &computers.at(i);
        }
        return NULL;
    }
}
/**
 * Método que recibe el id del nodo a ser buscado.
 * Método que valida si el nodo existe y retorna el nodo buscado.
 * @param id
 * @return
 */
NodeList<Computer>* Management::findNode(string id) {
    if (findComputer(id) == NULL) {
        return list->findNode(id);
    }
    return NULL;
}
/**
 * Método que recibe el id del objeto a ser buscado.
 * Método que retorna la información del objeto buscado.
 * @param id
 * @return
 */
Computer* Management::findInfo(string id) {

    if (findComputer(id) == NULL) {
        return list->findInfo(id);
    } else {
        return NULL;
    }
}
/**
 * Método que recibe tres parámetros donde contiene la información completa del
 * nodo que será agregado al inicio cuando haga la validacion de si el nodo existe si no se crea el nodo.
 * @param id
 * @param name
 * @param credits
 */
bool Management::addComputerFirst(string id, string name, int credits) {
    if (findComputer(id) == NULL) {
        if (!list->findNode(id)) {
            list->addBegin(Computer(id, name, credits));
            computers.push_back(Computer(id, name, credits));
            return true;
        }
    }
    return false;
}
/**
 * Método que recibe tres parámetros donde contiene la información completa del
 * nodo que será agregado al final cuando haga la validacion de si el nodo existe si no se crea el nodo.
 * @param id
 * @param name
 * @param credits
 */
bool Management::addComputerEnd(string id, string name, int credits) {
    if (findComputer(id) == NULL) {
        computers.push_back(Computer(id, name, credits));
        list->addEnd(Computer(id, name, credits));
        return true;
    }
    return false;
}

/**
 * Método que recibe tres parámetros donde contiene la información completa del
 * nodo,Donde valida si existe el nodo si no será agregado de manera ordenada.
 * @param id
 * @param name
 * @param credits
 */
bool Management::addComputerSorted(string id, string name, int credits) {
    if (findComputer(id) == NULL) {
        computers.push_back(Computer(id, name, credits));
        list->addSorted(Computer(id, name, credits));
        return true;
    }
    return false;
}
/**
 * Método que recibe la información de un nodo ya existente.
 * Método que recibe cuatro parámetros donde contiene la información completa del
 * nodo,Donde valida si el nodo ya existe si no será agregado antes del nodo seleccionado.
 * @param idBefore
 * @param id
 * @param name
 * @param credits
 */
bool Management::addComputerBeforeTo(string idBefore, string id, string name, int credits) {
    if (findComputer(id) == NULL) {
        if (!list->isEmpty()) {
            computers.push_back(Computer(id, name, credits));
            list->addBeforeTo(findNode(idBefore), Computer(id, name, credits));
            return true;
        } else {
            return false;
        }

    }
    return false;
}
/**
 * Método que recibe la información de un nodo ya existente.
 * Método que recibe cuatro parámetros donde contiene la información completa del
 * nodo,Donde valida si el nodo ya existe si no será agregado Despues del nodo seleccionado.
 * @param idBefore
 * @param id
 * @param name
 * @param credits
 */
bool Management::addComputerAfterTo(string idAfter, string id, string name, int credits) {

    if (findComputer(id) == NULL) {
        if (!list->isEmpty()) {
            computers.push_back(Computer(id, name, credits));
            list->addAfterTo(list->findNode(idAfter), Computer(id, name, credits));
            return true;
        } else {
            return false;
        }
    }
    return false;
}
/**Metodo que recibe  un parametro que contiene la posicion de un nodo
 * Método que valida si el nodo existe y retorna la posicion de un nodo
 * @return
 */
Computer* Management::getPos(int position) {
    if (!isEmpty()) {
        return list->getPos(position);
    }
    return NULL;

}
/**
 * Método que recibe un valor booleano donde valida si existe el nodo,
 * y retorna una lista en forma de vector para mostrar la informacion obtenida en esta
 * @param forward
 * @return
 */
vector<Computer> Management::getComputers(bool forward) {
    if (!isEmpty()) {
        return list->getList(forward);
    }

}
/**
 * Método que valida que el nodo exsite y retorna el primer nodo de la lista si existe el nodo
 * @return
 */
Computer Management::getFirst() {
    if (!list->isEmpty()) {
        return list->getFirst();
    }


}
/**
 * Método que valida que el nodo exsite y retorna el ultimo nodo de la lista si existe el nodo
 * @return
 */
Computer Management::getEnd() {
    if (!list->isEmpty()) {
        return list->getEnd();
    }

}

/**
 * Método que recibe el id de un nodo
 * Método que valida si el nodo existe y retorna la lista menos el nodo que acaba de ser eliminado
 * @param idNode
 * @return
 */
Computer Management::deleteNode(string idNode) {

    if (findComputer(idNode) != NULL) {
        NodeList<Computer>* aux = list->findNode(idNode);
        return list->deleteNode(aux);
    }


}

/**
 * Método que valida si el nodo existe y retorna el tamñano total de la lista de nodos
 * @return
 */
int Management::size() {
    if (!isEmpty()) {
        return list->size();
    }
    return 0;
}
/**
 * Método Destructor de la clase Managemen
 *
 */
Management::~Management() {
}

