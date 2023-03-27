#include "card.hpp"
#include <string>
using namespace ariel;


Card::Card(int number, std::string shape)
{
    this->shape = shape;
    this->value = number;
}


