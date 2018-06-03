//
// Created by idanc on 31/05/2018.
//
#include "Game.h"

#define NOT_EXIST_INDEX (-1)
//Constractor
Game::Game(int maxPlayers):
maxPlayers(maxPlayers), players_array(new Player[maxPlayers]), num_of_players(0) {}
//Assignment Operator:
//Methods:
GameStatus Game::addPlayer(const char* playerName,const char* weaponName,
                     Target target, int hit_strength){
    for (int i = 0; i < maxPlayers; ++i) {
        if(players_array[i].name && strcmp(playerName,players_array[i].name)==0) {
            return NAME_ALREADY_EXSISTS;
        }
    }
    Weapon new_weapon(weaponName,target,hit_strength);
    Player new_player(playerName, new_weapon);
    if(num_of_players==maxPlayers) return GAME_FULL;
    int i(0);
    for (i = 0; i < maxPlayers; ++i) {
        if(players_array[i].name==NULL) break;
    }
    players_array[i]=new_player;
    num_of_players++;
    return SUCCESS;

}
GameStatus Game::nextLevel(const char* playerName){
    for (int i = 0; i < maxPlayers; ++i) {
        if (strcmp(players_array[i].name,playerName)==0) {
            players_array[i].nextLevel();
            return SUCCESS;
        }
        return NAME_DOES_NOT_EXIST;
    }
}
GameStatus Game::makeStep(const char* playerName){
    for (int i = 0; i < maxPlayers; ++i) {
        if (strcmp(players_array[i].name,playerName)==0) {
            players_array[i].makestep();
            return SUCCESS;
        }
        return NAME_DOES_NOT_EXIST;
    }
}

GameStatus Game::addLife(const char* playerName){
    for (int i = 0; i < maxPlayers; ++i) {
        if (strcmp(players_array[i].name,playerName)==0) {
            players_array[i].addLife();
            return SUCCESS;
        }
        return NAME_DOES_NOT_EXIST;
    }
}
GameStatus Game::addStrength(const char* playerName, int strengthToAdd){
    if(strengthToAdd<0) return INVALID_PARAM;
    for (int i = 0; i < maxPlayers; ++i) {
        if (strcmp(players_array[i].name,playerName)==0) {
            players_array[i].addStrength(strengthToAdd);
            return SUCCESS;
        }
        return NAME_DOES_NOT_EXIST;
    }
}
bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength){
    bool players_removed=false;
    for (int i = 0; i < maxPlayers; ++i) {
        if(players_array[i].weaponIsWeak(weaponStrength)){
            delete &players_array[i];
            num_of_players--;
            players_removed= true;
        }
    }
    return players_removed;
}
GameStatus Game::fight(const char* playerName1, const char* playerName2){
    int a(NOT_EXIST_INDEX);
    int b(NOT_EXIST_INDEX);
    for (int i = 0; i < maxPlayers; ++i) {
        if(players_array[i].name &&
                strcmp(players_array[i].name,playerName1)==0){
            a=i;
        }
        if(players_array[i].name &&
                strcmp(players_array[i].name,playerName2)==0){
            b=i;
        }
    }
    if(a+b <0) return NAME_DOES_NOT_EXIST;
    if(!players_array[a].fight(players_array[b])) return FIGHT_FAILED;
    if(!players_array[a].isAlive()) {
        delete &players_array[a];
        players_array[a]=*(new Player());
        num_of_players--;
    }
    if(!players_array[b].isAlive()) {
        delete &players_array[b];
        players_array[b]=*(new Player());
        num_of_players--;
    }
    return SUCCESS;
}
//Print Operator:
std::ostream& operator<<(std::ostream& os, const Game& game){
    using std::endl;
    for (int i = 0; i < game.num_of_players; ++i) {
        os << "player " << i << ":" << game.players_array[i] << endl;
    }
    return os;
}