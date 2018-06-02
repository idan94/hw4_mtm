//
// Created by idanc on 31/05/2018.
//
#include "Game.h"


    //Constractor
    Game::Game(int maxPlayers):
    maxPlayers(maxPlayers), players_array() {
        players_array= new Player[maxPlayers]();

    }
