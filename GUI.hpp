#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "graphics.hpp"
#include <string>

using namespace genv;

class GUI{

private:
    std::string title;
    int wX, wY;
    event ev;

public:
    GUI();
    GUI(int widthX, int widthY, std::string window_name);
    void drawGame();
    void drawMenu(int &which);
    void open();
    event getEv() const;
};

#endif // GUI_HPP_INCLUDED
