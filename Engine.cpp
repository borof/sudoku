#include "Engine.hpp"
#include <iostream>
#include <sstream>
using namespace std;

Engine::Engine(){
    everyNumber = vector< vector<int> > (9, vector<int>(9));
}

vector< vector<int> > Engine::getEveryNumber(){
    return everyNumber;
}

void Engine::setEveryNumber(vector<vector<int> > configFile){
    everyNumber = configFile;
}

bool Engine::checkWin(){
    if(coordinates.empty())
        return true;
    return false;
}

void Engine::setEmptyNumber(vector<int> row, vector<int> col){
    for(int i = 0; i < row.size(); i++){
        Engine::Coord tmp;
        tmp.x = row[i];
        tmp.y = col[i];
        coordinates.push_back(tmp);
    }
}

vector<string> Engine::getValuesForGUI(){
    bool ok = false;
    vector<string>  tmp;
    for(int i = 0; i < everyNumber.size(); i++){
        for(int j = 0; j < everyNumber[i].size(); j++){
            for(int k = 0; k < coordinates.size(); k++){
                if(coordinates[k].x == i && coordinates[k].y == j){
                    ok = false;
                    break;
                }
                else{
                    ok = true;
                }
            }
            if(ok){
                tmp.push_back(static_cast<ostringstream*>( &(ostringstream() << everyNumber[i][j]) )->str());
            }
            else{
                tmp.push_back("");
            }
        }
    }
    return tmp;
}

void Engine::settingCoordinates(vector<int> del){
    //cout << del.empty() << endl;
    for(int i = 0; i < coordinates.size() && !del.empty(); i++){
        if(coordinates[i].x == del[0] && coordinates[i].y == del[1]){
            coordinates.erase(coordinates.begin() + i);
            break;
        }
    }
}
