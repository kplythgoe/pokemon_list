#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include "Pokedex.h"

using namespace std;

    void add_pokemon(Pokedex &pokedex, int id, std::string name, std::string type, std::string type2);
    void add_pokemon(Pokedex &pokedex, int id, std::string name, std::string type1, std::string type2) {
        if (!pokedex.add_pokemon(id,name,type1,type2)) 
            std::cout << name << " already exists" <<  std::endl;
    }
    void create_party(vector<int> picks);
    bool menu();
    
int main() {
    fstream in_file {"pokemon.txt", ios::in };
    if (in_file.is_open()) {
    } else {
       cout << "Could not find file" << endl;
    }
    
    int num_of_pokemon{0};
    string line;
    while (getline(in_file, line)) {
        num_of_pokemon++;
    }

    vector<int> picks{};
    srand((unsigned) time(0));
    int ranNum;
    int choice;
    
    cout << "Welcome to the Pokemon simulator. In the Pokemon simulator, you can look at a list of all the Pokemon from Gen 1 and get a randomly selected party of 6 Pokemon from Gen 1.\n" << endl;
    do {
        cout << "Please choose by number from the options provided\n" << endl;
        cout<<"1. Display all Pokemon from Gen 1" << endl;
        cout<<"2. Party Selector with no repeated Pokemon - Choose a party of 6 Pokemon at random" << endl;
        cout<<"3. Party Selector with possible repeated Pokemon - Choose a party of 6 Pokemon at random" << endl;
        cout<<"4. Choose your own party of Pokemon" << endl;
        cout<<"5. Quit\n" << endl;
        cout << "Please select a choice by number: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
            {
                system("cls");
                cout << "Here is a list of all of the Pokemon from Gen 1:" << endl;
                Pokedex all_pokemon;
                all_pokemon.repeat_false();
                in_file.clear();
                in_file.seekg(0, ios::beg);
                if(!all_pokemon.object_exists()) {
                    while (!in_file.eof()) {
                        string name, type1, type2;
                        int id;
                        in_file >> id >> name >> type1 >> type2;
                        add_pokemon(all_pokemon, id, name, type1, type2);
                    } 
                }
                all_pokemon.display();
                if (!menu())
                    return 0;
                else system("cls");
                break;
            }
                
            case 2:
            {
                system("cls");
                cout << "Party Selector with no repeated Pokemon" << endl;
                picks.clear();
                for (int i = 0; i < 6; i++) {
                    ranNum = (rand() % num_of_pokemon) + 1;
                    while (std::count(picks.begin(), picks.end(), ranNum)) {
                        ranNum = (rand() % num_of_pokemon) + 1;
                    }
                    picks.push_back(ranNum);
                }
                
                create_party(picks);
                if (!menu())
                    return 0;
                else system("cls");
                break;
            }   
            case 3:
            {
                system("cls");
                cout << "Party Selector with possible repeated Pokemon" << endl;
                picks.clear();
                for (int i = 0; i < 6; i++) {
                    ranNum = (rand() % num_of_pokemon) + 1;
                    picks.push_back(ranNum);
                }
                create_party(picks);
                if (!menu())
                    return 0;
                else system("cls");
                break;    
            }
            case 4:
            {
                system("cls");
                cout << "You have selected to choose your own party of 6\n" << endl;
                cout << "Do you want to be able to choose the same Pokemon multiple times?\n" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No\n" << endl;
                cout << "Please select a choice by number: ";
                cin >> choice;
                picks.clear();
                cout << "\nPlease enter 6 ID numbers of the Pokemon you want to choose (1 - 151)\n" << endl;
                cout << "Allow the same Pokemon multiple times: ";
                (choice == 1) ? cout << "YES\n\n" : cout << "NO\n\n";
                int pokemon_choice;
                for (int i {1} ; i <= 6 ; i++) {
                    cout << "Pokemon ID " << i << ": ";
                    cin >> pokemon_choice;
                    while (choice == 2 && count(picks.begin(), picks.end(), pokemon_choice)) {
                        char change;
                        cout << "\nYou selected to not allow multiple of the same Pokemon. Do you wish to change your decision? (Y/N): " ;
                        cin >> change;
                        if(change == 'Y') {
                        choice = 1;
                        cout << "\nAllow the same Pokemon multiple times: ";
                        (choice == 1) ? cout << "YES\n\n" : cout << "NO\n\n";
                        }
                        if (choice == 2) {
                            cout << "Pokemon ID " << i << ": ";
                            cin >> pokemon_choice;
                        }
                    }
                    picks.push_back(pokemon_choice);
                }
                create_party(picks);
                if (!menu())
                return 0;
                system("cls");
                break;
            }           
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                system("cls");
                
            if(!(cin>>choice)) {
                cout << "Error: you have entered an invalid value\n" << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
    } while (choice != 5);
    
    in_file.close();
    return 0;
}

void create_party(vector<int> picks) {
    Pokedex party;
    party.repeat_true();
    fstream in_file {"pokemon.txt", ios::in };
    if (in_file.is_open()) {
    } else {
       cout << "Could not find file" << endl;
    }
    while (!in_file.eof()) {
        string name, type1, type2;
        int id;
        in_file >> id >> name >> type1 >> type2;
        for (auto pick : picks) 
            if (id == pick) {
                add_pokemon(party, id, name, type1, type2);
            }
    }
    party.repeat_false();
    in_file.close();
    party.display();
}

bool menu() {
    cout << "1. Main menu" << endl;
    cout << "2. Quit\n" << endl;
    cout << "Please choose by number from the options provided: ";
    int choice;
    cin >> choice;
    if (choice == 2) {
        cout << "\nGoodbye!" << endl;
        return 0;
    }
    else {
        return 1;
    }
}