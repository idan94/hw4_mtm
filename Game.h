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
    SUCCESS
};
class Game{
    int maxPlayers;
    Player** players_array;
    int num_of_players;
public:
    //Constractor:
     explicit Game(int maxPlayers);
    //Destructor:
    ~Game();
    //Copy Constractor:
    Game(const Game& game);
    //Assignment Operator:
    Game& operator=(const Game& game);
    //Methods:
    /**
     * Add new player to the game.
     * @param playerName the player name
     * @param weaponName the weapon name
     * @param target the target of the weapon
     * @param hit_strength the hit strength of the weapon
     * @return SUCCESS- if the player added
     * NAME_ALREADY_EXSISTS- if the name of the player is already exist
     * GAME_FULL- if the game is full
     */
    GameStatus addPlayer(const char* playerName,const char* weaponName,
                         Target target, int hit_strength);
    /**
     * get a player name, and upgrade him to the next level
     * @param playerName the player name
     * @return SUCCESS- if level upgraded
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     */
    GameStatus nextLevel(const char* playerName);
    /**
     * get a player name, and move him one step
     * @param playerName the player name
     * @return SUCCESS- if player moved
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     */
    GameStatus makeStep(const char* playerName);
    /**
     * get a player name, and add him one life
     * @param playerName the player name
     * @return SUCCESS- if life added
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     */
    GameStatus addLife(const char* playerName);
    /**
     * get a player name, and upgrade his strength
     * @param playerName the player name
     * @param strengthToAdd how much strength to add
     * @return SUCCESS- strength added
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     * INVALID_PARAM- if 'strengthToAdd' is negative
     */
    GameStatus addStrength(const char* playerName, int strengthToAdd);
    /**
     *gets a number, and remove all the players that have weapon that is
     * weaker then the number
     * @param weaponStrength the number we compare with
     * @return true- if players has been removed
     * false- if not
     */
    bool removeAllPlayersWIthWeakWeapon(int weaponStrength);
    /**
     * gets 2 players, and make then fight, if one of them die- delete him
     * @param playerName1 the first player name
     * @param playerName2 the second player name
     * @return
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     * FIGHT_FAILED- if fight failed
     * SUCCESS- if fight happend
     */
    GameStatus fight(const char* playerName1, const char* playerName2);
    //Print Operator:
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    /**
     * reorder the array, move all players to the start of the array,
     * and all the empty index to the end.
     */
    void assignArrToLeft()const ;
    /**
     *  sort the player by names(lexicography)
     */
    void bubbleSortPlayers()const ;

};


#endif //HW4_MTM_GAME_H
