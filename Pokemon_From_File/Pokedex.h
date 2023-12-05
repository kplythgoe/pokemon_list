#ifndef __POKEDEX_H__
#define __POKEDEX_H__
#include <vector>
#include <string>
#include "Pokemon.h"

class Pokedex
{
    std::vector<Pokemon> pokedex;
    bool repeat_pokemon {false};

public:
    Pokedex();
    ~Pokedex();
    void display() const;
    bool add_pokemon(int id, std::string name, std::string type1, std::string type2);
    void repeat_true() { repeat_pokemon = true; }
    void repeat_false() { repeat_pokemon = false; }
    bool object_exists();
    void clear_party() { pokedex.clear(); }

};

#endif // __POKEDEX_H__
