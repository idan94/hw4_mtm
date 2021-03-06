//
// Created by idanc on 31/05/2018.
//
#include "Game.h"

#define NOT_EXIST_INDEX (-1)

//Constructor
Game::Game(int maxPlayers):
    maxPlayers(maxPlayers),
    players_array(new Player*[maxPlayers]),
    num_of_players(0) {
    for (int i = 0; i < maxPlayers; ++i) {
        players_array[i]= nullptr;
    }
}

//Destructor:
Game::~Game(){
    for (int i = 0; i < maxPlayers; ++i) {
        delete players_array[i];
    }
    delete []players_array;
}
//Copy Constractor:
Game::Game(const Game& game){
    maxPlayers=game.maxPlayers;
    num_of_players=game.num_of_players;
    for (int i = 0; i < maxPlayers; ++i) {
        players_array[i]=game.players_array[i];
    }
}
//Assignment Operator:
Game& Game::operator=(const Game& game){
    if(this == &game) return *this;
    delete []players_array;
    players_array=new Player*[maxPlayers];
    maxPlayers=game.maxPlayers;
    num_of_players=game.num_of_players;
    for (int i = 0; i < maxPlayers; ++i) {
        players_array[i]=game.players_array[i];
    }
    return *this;
}
//Methods:
GameStatus Game::addPlayer(const char* playerName,const char* weaponName,
                     Target target, int hit_strength) {
    if (num_of_players >= maxPlayers) return GAME_FULL;
    for (int i = 0; i < maxPlayers; ++i) {
        if (players_array[i] &&
            strcmp(playerName, players_array[i]->getName()) == 0) {
            return NAME_ALREADY_EXISTS;
        }
    }
    Weapon new_weapon(weaponName, target, hit_strength);


    int i(0);
    for (i = 0; i < maxPlayers; ++i) {
        if (!players_array[i]) break;
    }
    players_array[i] = new Player(playerName, new_weapon);
    num_of_players++;
    return SUCCESS;
}
GameStatus Game::nextLevel(const char* playerName) {
    for (int i = 0; i < maxPlayers; ++i) {
        if (players_array[i] && strcmp(players_array[i]->getName(), playerName) == 0) {
            players_array[i]->nextLevel();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}
GameStatus Game::makeStep(const char* playerName) {
    for (int i = 0; i < maxPlayers; ++i) {
        if (players_array[i] && strcmp(players_array[i]->getName(), playerName) == 0) {
            players_array[i]->makeStep();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::addLife(const char* playerName) {
    for (int i = 0; i < maxPlayers; ++i) {
        if (players_array[i] && strcmp(players_array[i]->getName(), playerName) == 0) {
            players_array[i]->addLife();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}
GameStatus Game::addStrength(const char* playerName, int strengthToAdd) {
    if (strengthToAdd < 0) return INVALID_PARAM;
    for (int i = 0; i < maxPlayers; ++i) {
        if (players_array[i] && strcmp(players_array[i]->getName(), playerName) == 0) {
            players_array[i]->addStrength(strengthToAdd);
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}
static void swap(Player &a, Player &b){
    Player temp=a;
    a=b;
    b=temp;
}
void Game::assignArrToLeft()const {
    for (int i = 0; i < maxPlayers; ++i) {
        for (int j = i; j < maxPlayers; ++j) {
            if(players_array[j] && players_array[i]){
                swap(*players_array[j],*players_array[i]);
                break;
            }
        }
    }
}
bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    bool players_removed = false;
    for (int i = 0; i < maxPlayers; ++i) {
        if (players_array[i] &&
            players_array[i]->weaponIsWeak(weaponStrength)) {
            Player &playA = *players_array[i];
            delete players_array[i];
            players_array[i]= nullptr;
            num_of_players--;
            players_removed = true;
        }
    }
    assignArrToLeft();
    return players_removed;
}
GameStatus Game::fight(const char* playerName1, const char* playerName2) {
    int a(NOT_EXIST_INDEX);
    int b(NOT_EXIST_INDEX);
    for (int i = 0; i < maxPlayers && (a==NOT_EXIST_INDEX || b==NOT_EXIST_INDEX); ++i) {
        if (players_array[i] && strcmp(players_array[i]->getName(), playerName1) == 0) {
            a = i;
        }
        if (players_array[i] && strcmp(players_array[i]->getName(), playerName2) == 0) {
            b = i;
        }
    }

    if (a==NOT_EXIST_INDEX || b==NOT_EXIST_INDEX) return NAME_DOES_NOT_EXIST;
    if (!players_array[a]->fight(*players_array[b])) return FIGHT_FAILED;
    if (!players_array[a]->isAlive()) {
        delete players_array[a];
        players_array[a]= nullptr;
        num_of_players--;
    }
    if (!players_array[b]->isAlive()) {
        delete players_array[b];
        players_array[b]= nullptr;
        num_of_players--;
    }
    assignArrToLeft();
    return SUCCESS;
}
//Print Operator:


void Game::bubbleSortPlayers()const {
    assignArrToLeft();
    for (int i = 0; i < maxPlayers-1; ++i) {
        for (int j = 0; j < maxPlayers-i-1; ++j) {
            if(players_array[j+1] && players_array[j]>players_array[j+1]){
                swap(*players_array[j],*players_array[j+1]);
            }
        }
    }
}
std::ostream& operator<<(std::ostream& os, const Game& game) {
    using std::endl;
    game.assignArrToLeft();
    game.bubbleSortPlayers();
    for (int i = 0; i < game.maxPlayers; ++i) {
        if (game.players_array[i] && game.players_array[i]->getName()) {
            os << "player " << i << ":" << *game.players_array[i] << endl;
        }
    }
    return os;
}