#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "GUI.hpp"
#include "Engine.hpp"

using namespace genv;

class GameMaster{

private:
    GUI gInterface;
    Engine gEngine;

public:
    GameMaster(int wX, int wY, std::string window_name);
    void start();
};

#endif // GAMEMASTER_HPP_INCLUDED
