#include "Engine.hpp"
#include <iostream>
using namespace std;
Engine::Engine(){
    everyNumber = vector< vector<int> > (9, vector<int>(9));
}


int Engine::getFeedback(int number, int x, int y){

}

void Engine::setEveryNumber(vector<vector<int> > configFile){
    everyNumber = configFile;
}

void Engine::setEmptyNumber(vector<int> row, vector<int> col){
    for(int i = 0; i < row.size(); i++){
        Engine::Coord tmp;
        tmp.x = row[i];
        tmp.y = col[i];
        coordinates.push_back(tmp);
    }
}
