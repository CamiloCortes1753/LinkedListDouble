
/*
 * File:   Computer.cpp
 * Author: Camilo Cortes
 *
 *
 */

#include <sstream>
#include <string>
#include <iostream>
#include "Computer.h"

/**
 * Método que recibe los parámetros vacios que van a ser usados
 */
Computer::Computer() {
    id = "";
    description = "";
    value = 0;
}

/**
 * Parámetros usados para guardar información de los nodos
 * @param id
 * @param description
 * @param value
 */
Computer::Computer(std::string id, std::string description, int value) {
    this->id = id;
    this->description = description;
    this->value = value;
}

/**
 * Parámetro que guarda el ID del nodo
 * @param id
 */
void Computer::setId(std::string id) {
    this->id = id;
}

/**
 * Parámetro que guarda la descripción del nodo
 * @param description
 */
void Computer::setDescription(std::string description) {
    this->description = description;
}

/**
 * Parámetro que guarda el valor del nodo
 * @param value
 */
void Computer::setValue(int value) {
    this->value = value;
}

/**
 * Método que retorna el ID
 * @return
 */
std::string Computer::getId() {
    return id;
}

/**
 * Método que retorna la descripción
 * @return
 */
std::string Computer::getDescription() {
    return description;
}

/**
 * Método que retorna el valor.
 * @return
 */
int Computer::getValue() {
    return value;
}

/**
 * Método que retorna la información completa del nodo
 * @return
 */
std::string Computer::toString() {
    std::string strValue = "";
    strValue = parseString(value);

    return "computer[id: " + id + ", description: " + description + ", value: " + strValue + "]";
}

/**
 * Método que recibe un parámetro de valor entero para convertirlo en una cadena
 * de caracteres.
 * @param value
 * @return
 */
std::string Computer::parseString(int value) {
    std::ostringstream aux;
    aux << value;
    return aux.str();
}

Computer::~Computer() {
}

