
/*
 * File:   RunLinkedListDouble.cpp
 * Author: Camilo Cortes
 *
 *
 */
#include "Management.h"
#include <cstdlib>
#include <iostream>
#include <future>

using namespace std;
Management* mng = new Management();


void addComputer(int n) {
    //Agregar al comienzo
    if (n == 1) {
        cout << "Ingrese el ID del computador: " << endl;
        string id;
        cin>>id;
        cout << "Ingrese descripción del computador: " << endl;
        string name;
        cin>>name;
        cout << "Ingrese valor del computador: " << endl;
        int credits;
        cin>>credits;
        cin.ignore();

        if (mng->addComputerFirst(id, name, credits)) {
            cout << "El computador se agrego correctamente" << endl;

        } else {
            cout << "El computador ya existe" << endl;
        }
    }//Agregar al final
    else if (n == 2) {
        cout << "Ingrese el ID del computador: " << endl;
        string id;
        cin>>id;
        cout << "Ingrese descripción del computador: " << endl;
        string name;
        cin>>name;
        cout << "Ingrese valor del computador: " << endl;
        int credits;
        cin>>credits;
        cin.ignore();
        if (mng->addComputerEnd(id, name, credits)) {

            cout << "El computador fue agregado correctamente" << endl;

        } else {
            cout << "El computador ya existe" << endl;
        }

        //Agregar antes de
    } else if (n == 3) {
        if (!mng->isEmpty()) {
            cout << "Ingrese el ID del computador: " << endl;
            string id;
            cin>>id;
            cout << "Ingrese descripción del computador: " << endl;
            string name;
            cin>>name;
            cout << "Ingrese valor del computador: " << endl;
            int credits;
            cin>>credits;
            cout << "Ingrese ID del computador siguiente donde va a guardar el computador creado: " << endl;
            string idNodo;
            cin>>idNodo;
            cin.ignore();

            if (mng->addComputerBeforeTo(idNodo, id, name, credits)) {
                cout << "El computador fue agregado correctamente" << endl;
            } else {
                cout << "El computador ya existe" << endl;
            }
        } else {
            cout << "No puede usar este método, primero debe crear un nodo con los otros métodos como: \n         1. Añadir al principio \n           2.Añadir al final" << endl;

        }
        //Agregar después de

    } else if (n == 4) {
        if (!mng->isEmpty()) {
            cout << "Ingrese ID del computador: " << endl;
            string id;
            cin>>id;
            cout << "Ingrese descripción del computador: " << endl;
            string name;
            cin>>name;
            cout << "Ingrese valor del computador: " << endl;
            int credits;
            cin>>credits;
            cout << "Ingrese ID del computador anterior donde va a guardar el computador creada: " << endl;
            string idNodo;
            cin>>idNodo;
            cin.ignore();

            if (mng->addComputerAfterTo(idNodo, id, name, credits)) {

                cout << "El computador fue agregado correctamente" << endl;
            } else {
                cout << "El computador ya existe" << endl;
            }
        } else {
            cout << "No puede usar este método, primero debe crear un nodo con los otros métodos como: \n         1. Añadir al principio \n           2.Añadir al final" << endl;

        }
        //Agregar ordenadamente
    } else if (n == 5) {
        cout << "Ingrese ID del computador: " << endl;
        string id;
        cin>>id;
        cout << "Ingrese descripción del computador: " << endl;
        string name;
        cin>>name;
        cout << "Ingrese valor del computador: " << endl;
        int credits;
        cin>>credits;
        cin.ignore();
        if (mng->addComputerSorted(id, name, credits)) {
            if (mng->findNode(id) == NULL) {
                cout << "El computador fue agregado correctamente" << endl;
            }
        } else {
            cout << "El computador ya existe" << endl;
        }
    }
}

//Menu agregar materias

void add() {
    string menuAdd = "--------Agregar Computador---------\n"
                     "1.Agregar al comienzo\n"
                     "2.Agregar al final\n"
                     "3.Agregar antes de\n"
                     "4.Agregar despues de\n "
                     "5.Agregar ordenadamente\n"
                     "6.Volver\n\n"
                     "Digite la opción que desea: ";

    char optionAdd;
    do {
        cout << menuAdd << endl;
        cin>>optionAdd;

        switch (optionAdd) {
            case '1':addComputer(1);
                break;
            case '2':addComputer(2);
                break;
            case '3':addComputer(3);
                break;
            case '4':addComputer(4);
                break;
            case '5':addComputer(5);
                break;

        }
        cin.clear();
    } while (optionAdd != '6');


}
//Buscar

void findComputer(int n) {
    //Buscar nodo

    if (n == 1) {
        if (!mng->isEmpty()) {
            cout << "Ingrese el código del nodo a buscar: " << endl;
            string idNode;
            cin>>idNode;

            if (mng->findNode(idNode) != NULL) {
                cout << "El nodo con el id  existe en la lista y es:" << endl;
                cout << mng->findInfo(idNode)->toString()<< endl;
            } else {
                cout << "El nodo con el id  no existe en la lista o es incorrecto" << endl;
            }
        } else {
            cout << "No hay nodos en la lista, debe ingresar nodos antes de realizar esta búsqueda" << endl;
        }


    }//Buscar objeto

    else if (n == 2) {
        if (!mng->isEmpty()) {
            cout << "Ingrese el código del computador a buscar: " << endl;
            string idComputer;
            cin>>idComputer;

            cout<<idComputer<<endl;
            if (mng->findInfo(idComputer) != NULL) {
                cout << "El computador existe" << endl;
                cout << mng->findInfo(idComputer)->toString() << endl;
            } else {
                cout << "El computador no existe\n" << endl;
            }
        } else {
            cout << "No hay nodos para buscar, debe ingresar nodos para que este disponible esta opción" << endl;
        }
    }
        //Buscar posicion del objeto
    else if (n == 3) {
        if (!mng->isEmpty()) {

            cout << "El tamaño de la lista es de: " << mng->size() << " computadores \n" << endl;
            cout << "Ingrese la posición del computador que busca: " << endl;
            int pos;
            cin>>pos;
            if (pos > mng->size()) {
                cout << "Debe ingresar un posición menor o igual al tamaño de la lista " << endl;
            } else if (pos < 0) {
                cout << "Debe ingresar un valor mayor a cero" << endl;
            } else {
                cout << "El computador en esa posición es: " << mng->getPos(pos)->toString() << endl;
            }
        } else {
            cout << "La lista esta vacía, no puede realizar está acción. Debe ingresar nodos" << endl;
        }

    }
}

void find() {
    string menuB = "------Menu búsqueda--------\n"
                   "1.Buscar Nodo\n"
                   "2.Buscar computador\n"
                   "3.Posición del computador en la lista\n"
                   "4.Volver\n\n "
                   "Digite la opción que desea: ";

    char optionB;

    do {
        cout << menuB << endl;
        cin>>optionB;

        switch (optionB) {
            case '1':findComputer(1);
                break;
            case '2':findComputer(2);
                break;
            case '3':findComputer(3);
                break;
        }
        cin.clear();
    } while (optionB != '4');
}

void getList(int n) {

    if (!mng->isEmpty()) {
        if (n == 1) {
            cout << "-----Lista de comienzo a fin----\n" << endl;
            for (int i = 0; i < mng->getComputers(true).size(); i++) {
                cout << mng->getComputers(true).at(i).toString() << endl;
            }
        } else if (n == 2) {
            cout << "-------Lista de fin a comienzo-----\n" << endl;
            for (int i = 0; i < mng->getComputers(false).size(); i++) {
                cout << mng->getComputers(false).at(i).toString() << endl;
            }
        } else if (n == 3) {
            cout << "El primer computador existente en la lista es: " << mng->getFirst().toString()<<endl;
        } else if (n == 4) {

            cout << "El último computador existente en la lista es: " << mng->getEnd().toString()<<endl;
        }
    } else {
        cout << "No hay elementos en la lita" << endl;
    }


}

void getListDouble() {
    string menuG = "---------Menu mostrar--------\n"
                   "1. Mostrar de principio a fin\n"
                   "2. Mostrar de fin a principio\n"
                   "3. Mostrar primer computador de la lista \n"
                   "4. Mostrar último computador de la lista \n"
                   "5. Volver\n\n "
                   "Digite una opción: ";

    char optionG;

    do {
        cout << menuG << endl;
        cin>>optionG;
        switch (optionG) {
            case '1':getList(1);
                break;
            case '2':getList(2);
                break;
            case '3': getList(3);
                break;
            case '4': getList(4);
                break;
        }
    } while (optionG != '5');
}

//Eliminar nodos
void deleteComputer() {
    if (!mng->isEmpty()) {
        cout << "Ingrese el código del computador que desea eliminar" <<endl;
        string id;
        cin>>id;
        cin.ignore();

        cout << "El nodo eliminado fue: " << mng->deleteNode(id).toString()<<endl;
    }else{
        cout<<"No hay nodos para eliminar, no se puede realizar esta acción"<<endl;
    }



}

void sizeList() {

    cout << "El tamaño de la lista es de: " << mng->size() << " computadores " <<endl;
}

void mainMenu() {
    string menuP = "--------Menu principal---------\n"
                   "1.Agregar Computador\n"
                   "2.Buscar\n"
                   "3.Mostrar\n"
                   "4.Eliminar\n"
                   "5.Cantidad Computador\n"
                   "0.Salir\n\n"
                   "Digite la opcion que desea: ";

    char option;
    do {
        cout << menuP << endl;
        cin>>option;

        switch (option) {
            case '1':add();
                break;
            case '2':find();
                break;
            case '3':getListDouble();
                break;
            case '4':deleteComputer();
                break;
            case '5':sizeList();
                break;
        }
        cin.clear();
    } while (option != '0');

}

int main(int argc, char** argv) {

    mainMenu();
    return 0;
}
