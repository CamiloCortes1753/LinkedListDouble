
/*
 * File:   Management.h
 * Author: Camilo Cortes
 *
 *
 */

#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Computer.h"
#include "NodeList.h"
#include <string>
#include <vector>

using namespace std;

class Management {
public:
    Management();
    bool isEmpty();

    Computer* findComputer(string id);
    NodeList<Computer>* findNode(string id);
    Computer* findInfo(string id);

    bool addComputerFirst(string id, string name, int credits);
    bool addComputerEnd(string id, string name, int credits);
    bool addComputerBeforeTo(string idBefore, string id, string name, int credits);
    bool addComputerAfterTo(string idAfter, string id, string name, int credits);
    bool addComputerSorted(string id, string name, int credits);

    Computer* getPos(int position);
    vector<Computer> getComputers(bool);
    Computer getFirst();
    Computer getEnd();

    Computer deleteNode(string id);
    int size();
    virtual ~Management();
private:
    vector<Computer> computers;
};

#endif //MANAGEMENT_H

