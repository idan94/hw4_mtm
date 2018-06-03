//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_PLAYER_H
#define HW4_MTM_PLAYER_H

#include <ostream>
#include "Weapon.h"

class Player {
    char *name;
    int level;
    int life;
    int strength;
    Weapon weapon;
    int player_location;
public:

    //Constructors
    Player(const char *name, const Weapon& weapon);
    //Destructor:
    ~Player();
    //Copy Constructor:
    Player(Player& player);
    //Assignment Operator:
    Player& operator=(const Player& player);
    //Methods:
    void nextLevel();
    bool isPlayer(const char* playerName) const;
    void makeStep();
    void addLife();
    void addStrength(int strengthToAdd);
    bool isAlive() const;
    const char* getName();
    bool weaponIsWeak(int weaponMinStrength) const;
    bool fight(Player& player);
    //Comparesion operators:
    bool operator<(Player player);
    bool operator>(Player player);
    friend bool operator==(Player player_a, Player player_b);
    //Print Operator:
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    //friend classes:

};

#endif //HW4_MTM_PLAYER_H
