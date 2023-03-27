#pragma once
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    class Game
    {
    private:
        Player& player1;
        Player& player2;

    public:
    
        Game(Player& pp1, Player& pp2);
        void playTurn();
        void playAll();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
     
    };
}