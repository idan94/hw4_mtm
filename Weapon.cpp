//
// Created by idanc on 31/05/2018.
//
#include <cstring>
#include "Weapon.h"

class Weapon{
    char* name;
    Target target;
    int hitStrength;

public:
    Weapon(const char* name, Target target, int hit_strength){
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->target=target;
        this->hitStrength=hit_strength;
    };
    ~Weapon() = default;
    Target getTarget() const{
        return this->target;
    }
    int getHitStrength() const{
        return this->hitStrength;
    }
};
