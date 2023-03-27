#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
using namespace ariel;
//1
TEST_CASE("create two player with their names")
{
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.playername == "Alice");
    CHECK(p2.playername == "Bob");
}
//2
TEST_CASE("cheak that the stack size equal at first")
{
   Player p1("Alice");
   Player p2("Bob");
   Game game(p1,p2); 
   game.playAll();
   CHECK(p1.stacksize()== p2.stacksize());
}
//3
TEST_CASE("the size of the stack at first need to be 26")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    
}
//4
TEST_CASE("at the first the cardes taken need be 0")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    }
//5
TEST_CASE("at the end the stack need be empty")
{
   Player p1("Alice");
   Player p2("Bob");
   Game game(p1,p2); 
   game.playAll();
   CHECK(p1.stacksize()== 0);
   CHECK(p2.stacksize()== 0);
}
//6
TEST_CASE("the amout that the players takes between 0-52")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playAll();
    bool op1 = (p1.cardesTaken() >= 0) && (p1.cardesTaken() <= 52);
    bool op2 = (p2.cardesTaken() >= 0) && (p2.cardesTaken() <= 52);
    CHECK(op1);
    CHECK(op2);  
}
//7
TEST_CASE("at the end the amout of alice plus the amout of bob takes is 52")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playAll();
    CHECK((p1.cardesTaken() + p2.cardesTaken()) == 52);
}
//8
TEST_CASE("after one turn one of the players takes cards")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    bool op = p1.cardesTaken() > 1 || p2.cardesTaken() > 1;
    CHECK(op);   
}
//9
TEST_CASE("after one turn the size of the stack is equal")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize() == p2.stacksize()); 
}
//10
TEST_CASE("after one turn in the stack have less than 26 cards")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    bool op = p1.stacksize() < 26 && p2.stacksize() < 26;
    CHECK(op);    
}
//11
TEST_CASE("after the game finish cant do another turn.")
{ 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
}
//12
TEST_CASE("check that the print Log not throws exception afetr one turn.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    CHECK_NOTHROW(game.printLog());   
}
//13
TEST_CASE("check that the print Stats not throws exception afetr one turn.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn(); 
    CHECK_NOTHROW(game.printStats()) ;   
}
//14
TEST_CASE("in the first the players have the same amount of cards.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    CHECK(p1.cardesTaken() == p2.cardesTaken()); 
}
//15
TEST_CASE("cheak that after the game if the cardes taken not equel throws excption.")
{ 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    bool op = p1.cardesTaken() != p2.cardesTaken();
    if(op)
    {
         CHECK_NOTHROW(game.printWiner());  
    }
    else
    {
        CHECK_THROWS(game.printWiner());  
    }
}
//16
TEST_CASE("at the first game the print log throws exception.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printLog()); 
}
//17
TEST_CASE("at the first game the print stats throws exception.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printStats()); 
}
//18
TEST_CASE("")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printWiner());    
}
//19
TEST_CASE("at the first game the print last turn throws exception.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn()); 
}
//20
TEST_CASE("after one turn and not finish the game trhows exception in printwiner.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    bool op = p1.stacksize() > 0 && p2.stacksize() > 0;
    if(op)
    {
        CHECK_THROWS(game.printWiner()); 
    }
    else
    {
        CHECK_NOTHROW(game.printWiner()); 
    }
}