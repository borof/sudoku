#include "StaticText.hpp"
#include "graphics.hpp"
#include "widgets.hpp"

#include <iostream>

using namespace genv;
using namespace std;

StaticText::StaticText(int x,int y,int sx,int sy,string s) : Widget(x,y,sx,sy),_text(s)
{

}

void StaticText::draw() const
{


    gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y);
    gout << move_to(_x+2,_y+2) << color(0,255,255) << box(_size_x-4,_size_y-4);
    gout << color(0,0,0);
    gout << move_to(_x+15,_y+15+gout.cascent()) << text(_text);



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
        if ( ev.button==btn_left and !is_selected(ev.pos_x, ev.pos_y))
        {

            focus=false;

        }
    }
}
