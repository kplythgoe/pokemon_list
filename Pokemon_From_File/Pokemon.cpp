#include "Pokemon.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

Pokemon::Pokemon(int id, std::string name, std::string type1, std::string type2)
    :id(id), name(name), type1(type1), type2(type2){

        }

//Pokemon::Pokemon() {
//    std::cout << "Calling default constructor" << std::endl;
//}

Pokemon::Pokemon(const Pokemon &source) 
    : Pokemon{source.id, source.name, source.type1, source.type2} {

}

Pokemon::~Pokemon()
{

}

void Pokemon::display() const {
    std::cout << std::setw(8) << std::left << id
                   << std::setw(15)  << name
                   << std::setw(15)  << type1
                   << std::setw(15)  << type2 << std::endl;
}