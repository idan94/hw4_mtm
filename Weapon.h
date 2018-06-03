//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_WEAPON_H
#define HW4_MTM_WEAPON_H
#include <ostream>
#include <cstring>


enum Target {
    LEVEL,
    STRENGTH,
    LIFE
};
class Weapon{
    char* name;
    Target target;
    int hitStrength;

public:
    //Constructor:
    Weapon(const char* name, Target target, int hit_strength);
    Weapon();
    //Destructor:
    ~Weapon() = default;
    //Copy Constractor:
    Weapon(Weapon& weapon);
    //Assignment Operator:
    Weapon& operator=(const Weapon& weapon);
    //Getters:
    Target getTarget() const;
    int getHitStrength() const;
    int getValue() const;
    //Comparesion operators:
    friend bool operator==(Weapon weapon_a, Weapon weapon_b);
    friend bool operator!=(Weapon weapon_a, Weapon weapon_b);
    bool operator>(Weapon weapon) ;
    bool operator<(Weapon weapon);
    //Print Operator:
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);
};



#endif //HW4_MTM_WEAPON_H
