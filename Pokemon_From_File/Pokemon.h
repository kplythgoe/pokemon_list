#ifndef __POKEMON_H__
#define __POKEMON_H__
#include <string>

class Pokemon
{
    int id;
    std::string name;
    std::string type1;
    std::string type2;
    int hp;
public:
//    Pokemon();
    Pokemon(int id, std::string name, std::string type1, std::string type2);
    
    Pokemon(const Pokemon &source);
    ~Pokemon();
    
    void display() const;

    std::string get_name() const { 

        return name; 
    }

};

#endif // __POKEMON_H__
