#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Engine{

private:
   struct Coord
    {
        int x = 0;
        int y = 0;
    };

    vector<Coord> coordinates;
    vector< vector<int> > everyNumber;
    bool win = false;

public:
    Engine();
    void setEveryNumber(vector<vector<int> > configFile);
    void setEmptyNumber(vector<int> row, vector<int> col);
    vector<string> getValuesForGUI();
    vector< vector<int> > getEveryNumber();
    void settingCoordinates(vector<int> del);
    bool checkWin();
};

#endif // ENGINE_HPP_INCLUDED
