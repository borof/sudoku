#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "graphics.hpp"
#include "StaticText.hpp"
#include "button.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

class GUI{

private:
    std::string title;
    int wX, wY;
    event ev;
    vector <Button*> butt;
    //int importantValues[3]; //szam x y tartalmaz
    vector< vector<StaticText*> > butt2;

public:
    GUI();
    GUI(int widthX, int widthY, std::string window_name);
    void drawGame(int importantValues[]);
    void drawMenu(int &which);
    void open();
    void  setEv(event evv);
    void clearScreen();
};

#endif // GUI_HPP_INCLUDED
