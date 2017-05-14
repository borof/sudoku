#include "StaticText.hpp"
#include "graphics.hpp"
#include "widgets.hpp"

#include <iostream>

using namespace genv;
using namespace std;

StaticText::StaticText(int x,int y,int sx,int sy,string s) : Widget(x,y,sx,sy),_text(s){
    bad_r = 0;
    bad_g = 255;
    bad_b = 255;
}

void StaticText::setBadRGB(bool badass){
    if(badass){
        bad_r = 255;
        bad_g = 127;
        bad_b = 80;
    }
    else{
        bad_r = 0;
        bad_g = 255;
        bad_b = 255;
    }
}

void StaticText::draw() const
{


    gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y);
    gout << move_to(_x+2,_y+2) << color(bad_r,bad_g,bad_b) << box(_size_x-4,_size_y-4);
    gout << color(0,0,0);
    gout << move_to(_x+15,_y+15+gout.cascent()) << text(_text);

    gout << move_to(_x, 3*_size_y+_size_y/2) << color(255,0,0) << line_to(9*_size_x+_size_x/2,3*_size_y+_size_y/2);
    gout << move_to(_x, 6*_size_y+_size_y/2) << color(255,0,0) << line_to(9*_size_x+_size_x/2,6*_size_y+_size_y/2);

    gout << move_to(3*_size_x+_size_x/2, _y) << color(255,0,0) << line_to(3*_size_x+_size_x/2,9*_size_y+_size_y/2);
    gout << move_to(6*_size_x+_size_x/2, _y) << color(255,0,0) << line_to(6*_size_x+_size_x/2,9*_size_y+_size_y/2);

}

void StaticText::handle(event ev)
{
    if (ev.button==btn_left and is_selected(ev.pos_x, ev.pos_y))
    {

        focus=true;

    }

    if (focus)
    {
        gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y);
        gout << move_to(_x+2,_y+2) << color(255,255,0) << box(_size_x-4,_size_y-4);
        gout << color(0,0,0);
        gout << move_to(_x+15,_y+15+gout.cascent()) << text(_text);

    }

    if (focus)
    {
        if (ev.keycode >= '1' && ev.keycode <= '9')
        {

            _text = _text + (char)ev.keycode;
        }

        if (gout.twidth(_text) > _size_x)
        {
            _text.resize(_text.length()-1);
        }

        if (ev.keycode == key_backspace && _text.length() != 0)
        {
            _text.resize(_text.length()-1);
        }

        if (ev.button == btn_left and !is_selected(ev.pos_x, ev.pos_y))
            focus=false;
    }
}

void StaticText::setText(string str){
    _text = str;
}
