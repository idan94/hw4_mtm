//
// Created by idanc on 31/05/2018.
//
#include "Player.h"


//Constractor
Player::Player(const char *name, const Weapon& weapon):
    level(1), life(1), strength(1), player_location(0),
    name(), weapon(){
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->weapon=weapon;

}

Player::Player():
    level(1), life(1), strength(1), player_location(0),
    name(nullptr), weapon(){}

void Player::nextLevel(){
    level++;
}
bool Player::isPlayer(const char* playerName) const{
    return bool(strcmp(playerName, name));
}
void Player::makestep(){
    player_location++;
}
void Player::addLife(){
    life++;
}
void Player::addStrength(int strengthToAdd) {
    strength+=strengthToAdd;
}
void Player::isAlive() const {

}