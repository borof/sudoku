#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "GUI.hpp"
#include "Engine.hpp"
#include <iostream>

using namespace std;
using namespace genv;

class GameMaster{

private:
    GUI gInterface;
    Engine gEngine;

public:
    GameMaster(int wX, int wY, string window_name);
    void start();
    void readConfig(int which);
};

#endif // GAMEMASTER_HPP_INCLUDED
