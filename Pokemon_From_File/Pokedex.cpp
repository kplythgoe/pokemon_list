#include <iostream>
#include <iomanip>
#include "Pokedex.h"

Pokedex::Pokedex() {

}

Pokedex::~Pokedex() {

}

void Pokedex::display() const {
    if (pokedex.size() == 0) {
        std::cout << "\nSorry, no Pokemon to display\n" << std::endl;
    } else {
        std::cout << "\n" << std::setfill('=') << std::setw(75) << "" << std::setfill(' ')  << "\n" << std::endl;
        std::cout << std::setw(8) << std::left << "Id";
        std::cout << std::setw(15) << std::left << "Name";
        std::cout << std::setw(15) << "Type 1";
        std::cout << std::setw(15) << "Type 2" << std::endl;;
        std::cout << std::setfill('-') << std::setw(75) << "" << std::setfill(' ')  << std::endl;
        
        for (const auto &pokemon: pokedex)
            pokemon.display();
        std::cout << "\n" << std::setfill('=') << std::setw(75) << "" << std::setfill(' ')  << "\n" << std::endl;
    }
}

bool Pokedex::add_pokemon(int id, std::string name, std::string type1, std::string type2) {
    for (Pokemon &pokemon : pokedex) {
        if (pokemon.get_name() == name && !repeat_pokemon) 
            return false;
    }
    Pokemon temp {id, name, type1, type2};
    pokedex.push_back(temp);
    return true;
}

bool Pokedex::object_exists() {
    if (pokedex.size() > 0)
        return true;
    else {
        return false;
    }
}