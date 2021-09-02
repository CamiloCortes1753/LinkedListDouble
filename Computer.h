
/*
 *
 * Author: Camilo Cortes
 *
 *
 */

#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

class Computer {
public:
    Computer();
    Computer(std::string, std::string, int);
    void setId(std::string);
    void setDescription(std::string);
    void setValue(int);

    std::string getId();
    std::string getDescription();
    int getValue();
    std::string toString();
    virtual ~Computer();
private:
    std::string id;
    std::string description;
    int value;
    std::string parseString(int);

};

#endif /* COMPUTER_H */

