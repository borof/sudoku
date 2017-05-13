#include "StaticText.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

StaticText::StaticText(int x,int y,int sx,int sy,string s) : Widget(x,y,sx,sy),_text(s){
//    _selected = false;
}

void StaticText::draw() const
{
    gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y);
    gout << move_to(_x+2,_y+2) << color(0,0,0) << box(_size_x-4,_size_y-4);
    //if(_selected){
        gout << color(255,255,255);
        gout << move_to(_x+5,_y+5+gout.cascent()) << text(_text);
   // } else {
        //gout << color(255,255,255);
        //gout << move_to(_x+5,_y+5+gout.cascent()) << text(_text);
    //}
}
#include <iostream>
void StaticText::handle(event ev) {
    if ( ev.type == ev_key && ev.keycode >= '0' && ev.keycode <= 'z')
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
    if (ev.keycode == key_enter)
        {
            _text.clear();
        }
}
