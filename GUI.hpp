#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "graphics.hpp"
#include "button.hpp"
#include "StaticText.hpp"
#include <string>
#include <iostream>
using namespace genv;
using namespace std;
class GUI{

private:
    string title;
    int wX, wY;
    vector<Button*> butt;
    vector< vector<StaticText*> > butt2;
    event ev;

public:
    GUI();
    GUI(int widthX, int widthY, string window_name);
    void drawGame();
    void drawMenu(int &which);
    void open();
    void setEv(event even);
    void clearScreen();
    void loadDatas(vector<string> values);
    vector<int> check(vector<string> values, vector<vector<int> > all);
    void win();
};

#endif // GUI_HPP_INCLUDED
