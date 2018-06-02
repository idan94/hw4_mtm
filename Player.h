//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_PLAYER_H
#define HW4_MTM_PLAYER_H
#include "Weapon.h"

class Player {
    char *name;
    int level;
    int life;
    int strength;
    Weapon weapon;
    int player_location;

public:
    //Constractors
    Player(const char *name, const Weapon& weapon);
    Player();
    //Destcator:
    ~Player()= default;
    //Methods:
    void nextLevel();
    bool isPlayer(const char* playerName) const;
    void makestep();
    void addLife();
    void addStrength(int strengthToAdd);
    void isAlive() const;
};

#endif //HW4_MTM_PLAYER_H
