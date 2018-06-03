//
// Created by idanc on 31/05/2018.
//
#include <cstring>
#include "Weapon.h"


//Constructors:
Weapon::Weapon(const char *name, Target target, int hit_strength):
    target(target),
    hitStrength(hit_strength),
    name(nullptr) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Weapon::Weapon():
target(Target(0)),hitStrength(0),name(nullptr){}


//Copy Constructor:
Weapon::Weapon(Weapon& weapon) :
    target(weapon.target),
    hitStrength(weapon.hitStrength),
    name(new char[strlen(weapon.name)+1])
{
    strcpy(name,weapon.name);
}

//Assignment Operator:
Weapon& Weapon::operator=(const Weapon& weapon){
    if(this == &weapon) return *this;

    name=new char[strlen(weapon.name)+1];
    strcpy(name,weapon.name);
    target=weapon.target;
    hitStrength=weapon.hitStrength;
    return *this;
}


//Getters:
Target Weapon::getTarget() const {
    return target; //return this->target
}

int Weapon::getHitStrength() const {
    return hitStrength; //return this->hitStrength
}

int Weapon::getValue() const {
    int target = getTarget();
    int hit_strength = getHitStrength();
    return (target+1) * hit_strength;
}

//Comparesion operators:
bool Weapon::operator>(Weapon weapon) {
    return (getValue() > weapon.getValue());
}

bool Weapon::operator<(Weapon weapon) {
    return (getValue() < weapon.getValue());
}

bool operator==(Weapon weapon_a, Weapon weapon_b) {
    return (weapon_a.getValue() == weapon_b.getValue());
}

bool operator!=(Weapon weapon_a, Weapon weapon_b)  {
    return (weapon_a.getValue() != weapon_b.getValue());
}
//Print Operator:
std::ostream& operator<<(std::ostream& os, const Weapon& weapon){
    os << "{weapon name: "<<weapon.name << ", weapon value:"<<weapon.getValue()<<"}" ;
    return os;
}