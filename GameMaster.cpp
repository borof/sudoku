#include "GameMaster.hpp"
#include <iostream>
using namespace std;
GameMaster::GameMaster(int widthX, int widthY, std::string window_name){
    gInterface = GUI(widthX, widthY, window_name);
    gEngine = Engine();
}

void GameMaster::start(){
    gInterface.open();

    int config = -1;

    event ev = gInterface.getEv();

    while(gin>>ev){
        event ev = gInterface.getEv();
        gInterface.drawMenu(config);
    }
}
