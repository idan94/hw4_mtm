//
// Created by idanc on 31/05/2018.
//

#include "Player.h"

static void changeNegativeToZero(int &num){
    if(num<0){
        num=0;
    }
}

//Constractor
Player::Player(const char *name, const Weapon& weapon):
        name(),
        level(1),
        life(1),
        strength(1),
        weapon(),
        player_location(0)
        {
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->weapon=weapon;
}


//Destructor:
Player::~Player(){
    delete []name;
}
//Copy Constructor:
Player::Player(const Player& player):
    name(new char[strlen(player.name)+1]),
    level(player.level),
    life(player.life),
    strength(player.strength),
    weapon(player.weapon),
    player_location(player.player_location)
    {
        strcpy(name,player.name);
    }
//Assignment Operator:
Player& Player::operator=(const Player& player) {
    if (this == &player) {
        return (*this);
    }
    delete []name;
    name = new char[strlen(player.name) + 1];
    strcpy(name,player.name);
    level=player.level;
    life=player.life;
    strength=player.strength;
    weapon=player.weapon;
    player_location=player.player_location;
    return *this;
}
void Player::nextLevel(){
    level++;
}
bool Player::isPlayer(const char* playerName) const{
    return bool(strcmp(playerName, name));
}
void Player::makeStep(){
    player_location++;
}
void Player::addLife(){
    life++;
}
void Player::addStrength(int strengthToAdd) {
    strength+=strengthToAdd;
}
const char* Player::getName(){
    return name;
}
bool Player::isAlive() const {
    return (level>0 && life>0 && strength>0);
}
bool Player::weaponIsWeak(int weaponMinStrength) const {
    return (weapon.getValue()<weaponMinStrength);
}
bool Player::fight(Player &player) {
    if(player.player_location != player_location
       || player.weapon==weapon) return false;
    if(player.weapon>weapon){
        switch (player.weapon.getTarget()){
            case(LEVEL): {
                level -= player.weapon.getHitStrength();
                changeNegativeToZero(level);
                break;
            }
            case(STRENGTH):{
                strength-=player.weapon.getHitStrength();
                changeNegativeToZero(strength);
                break;
            }
            case (LIFE):{
                life-=player.weapon.getHitStrength();
                changeNegativeToZero(life);
                break;
            }
        }
    } else{
        switch (weapon.getTarget()){
            case(LEVEL): {
                player.level -= weapon.getHitStrength();
                changeNegativeToZero(level);
                break;
            }
            case(STRENGTH):{
                player.strength-=weapon.getHitStrength();
                changeNegativeToZero(strength);
                break;
            }
            case (LIFE):{
                player.life-=weapon.getHitStrength();
                changeNegativeToZero(life);
                break;
            }
        }
    }
    return true;
}

//Comparesion operators:
bool Player::operator>(Player player)  {
    return(strcmp(this->name, player.name)>0);
}
bool Player::operator<(Player player)  {
    return(strcmp(this->name, player.name)<0);
}

bool operator==(Player player_a, Player player_b) {
    return (strcmp(player_a.name,player_b.name)==0);
}

//Print Operator:
std::ostream& operator<<(std::ostream& os, const Player& player){
    os << "{player name: "<<  player.name<< " ,weapon: " <<player.weapon<< "}";
    return os;
}
