#include "button.hpp"
#include "widgets.hpp"
#include "GUI.hpp"
#include <iostream>
using namespace std;

using namespace genv;

Button::Button(int x,int y,int sx,int sy,string s, int which_) : Widget(x,y,sx,sy),_text(s) {}
void Button::draw() const
{
    gout << move_to(_x,_y) << color(0,255,255) << box(_size_x,_size_y);
    gout << move_to(_x+2,_y+2) << color(0,0,255) << box(_size_x-4,_size_y-4);

    gout << color(255,255,255); // Szoveg szine;
    gout << move_to(_x+5,_y+5+gout.cascent()) << text(_text);
}



void Button::click(int &result)
{
    if (is_selected(ev.pos_x, ev.pos_y))
    {
        if (ev.button == btn_left)
            {
                result = which;
                cout << result << endl;
            }
    }
}

