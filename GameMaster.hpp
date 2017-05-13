#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "GUI.hpp"
#include "Engine.hpp"

class GameMaster{

private:
    GUI gInterfac;
    Engine gEngine;

public:
    GameMaster();
    start();
};

#endif // GAMEMASTER_HPP_INCLUDED
