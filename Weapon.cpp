//
// Created by idanc on 31/05/2018.
//
#include <cstring>
#include "Weapon.h"



    Weapon::Weapon(const char *name, Target target, int hit_strength):
    target(target), hitStrength(hit_strength),name(nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Weapon::Weapon():
    target(Target(0)),hitStrength(0),name(nullptr){}

    Target Weapon::getTarget() const {
        return target; //return this->target
    }

    int Weapon::getHitStrength() const {
        return hitStrength; //return this->hitStrength
    }

    int Weapon::getValue() const {
        int target = getTarget();
        int hit_strength = getHitStrength();
        return target * hit_strength;
    }

    bool Weapon::operator>(Weapon weapon) {
        if (getValue() > weapon.getValue()) return true;
        return false;
    }

    bool Weapon::operator<(Weapon weapon) {
        if (getValue() < weapon.getValue()) return true;
        return false;
    }

    bool operator==(Weapon weapon_a, Weapon weapon_b) {
        if (weapon_a.getValue() == weapon_b.getValue()) return true;
        return false;
    }

    bool operator!=(Weapon weapon_a, Weapon weapon_b) {
        if (weapon_a.getValue() != weapon_b.getValue()) {
            return true;
        }
        return false;
    }
