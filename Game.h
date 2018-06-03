//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_GAME_H
#define HW4_MTM_GAME_H
#include <ostream>
#include "Player.h"
#include "Weapon.h"

enum GameStatus{
    INVALID_PARAM,
    NAME_ALREADY_EXSISTS,
    GAME_FULL,
    NAME_DOES_NOT_EXIST,
    FIGHT_FAILED,
    SUCCESS,
};
class Game{
    int maxPlayers;
    Player* players_array;
    int num_of_players;
public:
    //Constractor:
    Game(int maxPlayers);
    //Destractor:
    ~Game() = default;
    //Copy Constractor:
    Game(Game& game)= default;
    //Assignment Operator:
    Game& operator=(const Game& game) = default;
    //Methods:
    GameStatus addPlayer(const char* playerName,const char* weaponName,
                         Target target, int hit_strength);
    GameStatus nextLevel(const char* playerName);
    GameStatus makeStep(const char* playerName);
    GameStatus addLife(const char* playerName);
    GameStatus addStrength(const char* playerName, int strengthToAdd);
    bool removeAllPlayersWithWeakWeapon(int weaponStrength);

    GameStatus fight(const char* playerName1, const char* playerName2);
    //Print Operator:
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};


#endif //HW4_MTM_GAME_H
