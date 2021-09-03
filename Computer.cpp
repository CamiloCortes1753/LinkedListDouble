
/*
 * File:   Computer.cpp
 * Author: Camilo Cortes
 *
 */

#include "Computer.h"
#include <sstream>

Computer::Computer() {
    this->id = "";
    this->description = "";
    this->value = 0;

}

Computer::Computer(string id, string description, int value) {
    this->id = id;
    this->description = description;
    this->value = value;
}

string Computer::getId() {
    return id;
}

string Computer::getDescription() {
    return description;
}

int Computer::getValue() {
    return value;
}

void Computer::setId(string id) {
    this->id = id;
}

void Computer::setDescription(string description) {
    this->description = description;
}

void Computer::setValue(int value) {
    this->value = value;
}

string Computer::parseInt(int value) {
    ostringstream aux;
    aux<<value;
    return aux.str();
}

string Computer::toString() {

    string values = parseInt(value);
    return "Id=" + id + ", Description:" + description + ", Value:" + values;
}

Computer::~Computer() {
}

