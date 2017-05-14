#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include <string.h>

using namespace std;
using namespace genv;

class Button : public Widget
{
protected:
    string _text;
    int which;

public:
    Button(int x,int y,int sx,int sy,string s, int which_);
    virtual void draw() const;
    virtual void click(int &result, event ev);
};



#endif // BUTTON_HPP_INCLUDED
