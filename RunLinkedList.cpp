
/*
 * File:   RunLinkedList.cpp
 *
 *
 *
 */

#include "Node.h"
#include "Computer.h"
#include "LinkedListDouble.h"
#include "LinkedListDouble.cpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

LinkedListDouble<Computer>* listComputer = new LinkedListDouble<Computer>();
void menu();
void printList(LinkedListDouble<Computer>*);

/*
 *
 */
int main(int argc, char** argv) {
    menu();

    return 0;
}

void menu() {
    string menu = "------Menu------\n"
                  "\n1. ¿La Lista está Vacia?"
                  "\n2. Adicionar computador al Inicio"
                  "\n3. Adicionar computador al Final"
                  "\n4. Adicionar computador Despues de... "
                  "\n5. Adicionar computador Antes de... "
                  "\n6. Adicionar Ordenado"
                  "\n7. Obtener Informacion Nodo en la Posicion"
                  "\n8. Tamaño"
                  "\n9. Buscar Nodo"
                  "\n10. Buscar Objeto"
                  "\n11. Borrar Nodo"
                  "\n12. Obtener Listado de Nodos"
                  "\n13. Salir\n";

    int option;
    do {
        cout << menu;
        cin >> option;
        cin.ignore();

        switch(option) {
            case 1: {
                cout << "¿La Lista está Vacia?" << endl;

                if(listComputer->isEmpty() == 1) {
                    cout << "Lista Vacia" << endl;
                } else {
                    cout << "La Lista contiene Objetos" << endl;
                }
                break;
            }

            case 2:{
                std::string id;
                std::string description;
                int value;
                cout << "Adicionar computador Al Inicio" <<endl;
                cout << "Digite el ID del computador" << endl;
                cin >> id;

                if(listComputer->findNode(id)) {
                    cout << "El ID existe, no es agregado" << endl;
                } else {
                    cout << "El ID NO existe, sera agregado, inserte informacion restante\n" << endl;
                    cout << "Digite una Descripcion del computador" << endl;
                    cin >> description;
                    cout << "Digite el Valor del computador" << endl;
                    cin >> value;

                    listComputer->addNodeFirst(Computer(id, description, value));
                }
                break;
            }

            case 3:{
                std::string id;
                std::string description;
                int value;
                cout << "Adicionar computador Al Final" <<endl;
                cout << "Digite el ID del computador" << endl;
                cin >> id;
                if(listComputer->findNode(id)) {
                    cout << "El ID existe, no es agregado" << endl;
                } else {
                    cout << "El ID NO existe, sera agregado, inserte informacion restante\n" << endl;
                    cout << "Digite una Descripcion del computador" << endl;
                    cin >> description;
                    cout << "Digite el Valor del computador" << endl;
                    cin >> value;

                    listComputer->addNodeLast(Computer(id, description, value));
                }
                break;
            }

            case 4:{
                std::string idFind;
                std::string id;
                std::string description;
                int value;
                cout << "Adicionar computador Despues de..." <<endl;
                cout << "Digite el Id del computador Anterior" << endl;
                cin >> idFind;

                if(listComputer->findNode(idFind)) {
                    cout << "computador Encontrado" << endl;
                    cout << "Digite el ID del cmmputador a Agregar Despues" << endl;
                    cin >> id;
                    cout << "Digite una Descripcion del computador" << endl;
                    cin >> description;
                    cout << "Digite el Valor del computador" << endl;
                    cin >> value;

                    listComputer->addNodeAfterTo(listComputer->findNode(idFind), Computer(id, description, value));
                }
                break;
            }

            case 5:{
                std::string idFind;
                std::string id;
                std::string description;
                int value;
                cout << "Adicionar computador Antes de..." <<endl;
                cout << "Digite el Id del computador Despues" << endl;
                cin >> idFind;

                if(listComputer->findNode(idFind)) {
                    cout << "computador Encontrado" << endl;
                    cout << "Digite el ID del computador a Agregar Despues" << endl;
                    cin >> id;
                    cout << "Digite una Descripcion del computador" << endl;
                    cin >> description;
                    cout << "Digite el Valor del computador" << endl;
                    cin >> value;

                    listComputer->addNodeBeforeTo(listComputer->findNode(idFind), Computer(id, description, value));
                }
                break;
            }

            case 6:{
                cout << "Adicionar Ordenado" << endl;
                std::string id;
                std::string description;
                int value;
                cout << "Adicionar computador Al Final" <<endl;
                cout << "Digite el ID del computador" << endl;
                cin >> id;
                if(listComputer->findNode(id)) {
                    cout << "El ID existe, no es agregado" << endl;
                } else {
                    cout << "El ID NO existe, sera agregado, inserte informacion restante\n" << endl;
                    cout << "Digite una Descripcion del computador" << endl;
                    cin >> description;
                    cout << "Digite el Valor del computador" << endl;
                    cin >> value;

                    listComputer->addNodeSorted(Computer(id, description, value));
                }
                break;
            }
            case 7:{
                std::string id;
                cout << "Buscar Nodo" << endl;
                cout << "Digite el Id a consultar" << endl;
                cin >> id;
                cout <<listComputer->findInfo(id)<< endl;
                break;
            }
            case 8:{
                cout << "Tamaño" << endl;
                cout << listComputer->getLinkedList(0).size() << endl;
                break;
            }

            case 9:{
                std::string id;
                cout << "Buscar Nodo" << endl;
                cout << "Digite el Id a consultar" << endl;
                cin >> id;
                if(listComputer->findNode(id)) {
                    cout << "El Nodo Existe" << endl;
                } else {
                    cout << "El Nodo NO Existe" << endl;
                }
                break;
            }

            case 10:{
                std::string id;
                cout << "Buscar Objeto" << endl;
                cout << "Digite el Id a consultar" << endl;
                cin >> id;
                if(listComputer->findNode(id)) {
                    cout << "El Objeto Existe" << endl;
                } else {
                    cout << "El Objeto NO Existe" << endl;
                }
                break;
            }

            case 11:{
                std::string id;
                cout << "Borrar Nodo" << endl;
                cout << "Digite el Id a Borrar" << endl;
                cin >> id;

                if(listComputer->findNode(id)) {
                    cout << "El Nodo Existe" << endl;
                    Computer pro = listComputer->deleteNode(listComputer->findNode(id));
                    cout << "Nodo Borrado--> " << pro.toString() << endl;
                } else {
                    cout << "El Nodo NO Existe" << endl;
                }
            }

            case 12:{
                cout << "Listado de Nodos" << endl;
                printList(listComputer);
            }
        }
    } while(option != 13);
}

void printList(LinkedListDouble<Computer>* list) {
    std::vector<Computer> vec = list->getLinkedList(1);

    for(int i = 0; i < vec.size(); i++) {
        cout << vec.at(i).toString() << endl;
    }
}
