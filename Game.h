//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_GAME_H
#define HW4_MTM_GAME_H

#include "Player.h"
#include "Weapon.h"
class Game{
    int maxPlayers;
    Player* players_array;

public:
    //Constractor
    Game(int maxPlayers);
    //Destractor:
    ~Game() = default;

};


#endif //HW4_MTM_GAME_H
