#include <string>
#include "player.hpp"
using namespace std;
using namespace ariel;

Player::Player(std:: string name)
{
    this->playername = name;
}

int Player::stacksize()
{
    return 0;
}

int Player::cardesTaken()
{
    return 0;
}