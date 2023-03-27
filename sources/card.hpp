#pragma once
#include <string>

namespace ariel
{
    class Card
    {
        public:
            int value;
            std::string shape;
            Card(int value, std::string shape);
    };
}