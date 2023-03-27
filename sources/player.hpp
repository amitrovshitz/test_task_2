#pragma once
#include <string>
using namespace std;
namespace ariel
{
    class Player
    {
        public:
        std::string playername;
        Player(std::string name);
        int stacksize();
        int cardesTaken();
    };
}
