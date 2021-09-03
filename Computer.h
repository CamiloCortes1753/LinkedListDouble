
/*
 * File:   Computer.hpp
 * Author: Camilo Cortes
 *
 *
 */

#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer {
public:
    Computer();
    Computer(string id, string name, int credits );
    string getId();
    string getDescription();
    int getValue();
    void setId(string id);
    void setDescription(string description);
    void setValue(int value);
    string toString();
    virtual ~Computer();
private:
    string id;
    string description;
    int value;
    string parseInt(int value);

};

#endif  //COMPUTER_H

