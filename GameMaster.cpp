#include "GameMaster.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
GameMaster::GameMaster(int widthX, int widthY, string window_name){
    gInterface = GUI(widthX, widthY, window_name);
    gEngine = Engine();
}

void GameMaster::start(){
    gInterface.open();
    int config = -1;
    event ev;

    while(gin>>ev){
        gInterface.setEv(ev);
        gInterface.drawMenu(config);
        if(config != -1){
            gInterface.clearScreen();
            break;
        }
    }
    readConfig(config);
    config = -1;
    while(gin>>ev && !gEngine.checkWin()){
        gInterface.setEv(ev);
        gInterface.loadDatas(gEngine.getValuesForGUI());
        gInterface.drawGame();
        gEngine.settingCoordinates(gInterface.check(gEngine.getValuesForGUI(), gEngine.getEveryNumber()));
        if(gEngine.checkWin()){
            gInterface.clearScreen();
            gInterface.win();
        }

    }
}

void GameMaster::readConfig(int which){
    ifstream myfile;
    int missingPlaceNumber = 0;

    switch(which){
        case 1:
            myfile.open(".\\conf\\easy.conf.txt"); missingPlaceNumber = 17; break;
        case 2:
            myfile.open(".\\conf\\medium.conf.txt"); missingPlaceNumber = 47; break;
        case 3:
            myfile.open(".\\conf\\hard.conf.txt"); missingPlaceNumber = 51; break;
        case 4:
            myfile.close();
            exit(EXIT_SUCCESS);
        default:
            myfile.close();
            exit(EXIT_FAILURE); break;
    }

    int temporary = -1;
    vector<vector<int> > full(9, vector<int>(9));
    vector<int> emptyRowInd;
    vector<int> emptyColInd;

    for(int i =0; i < full.size(); i++){
        for(int j = 0; j < full[i].size(); j++){
            myfile >> temporary;
            full[i][j] = temporary;
        }
    }

    int ind = 0;
    int ind_ = 0;
    while(myfile >> temporary){
        if(ind < missingPlaceNumber){
            emptyRowInd.push_back(temporary);
            ind++;
        }
        else{
            emptyColInd.push_back(temporary);
            ind_++;
        }
    }

    gEngine.setEveryNumber(full);
    gEngine.setEmptyNumber(emptyRowInd, emptyColInd);
}
