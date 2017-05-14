#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;
using namespace std;

class StaticText : public Widget{

    string _text;
    bool focus = false;
    int bad_r, bad_g, bad_b;
public:
    string GetText (){return _text;}

    StaticText(int,int,int,int,string);
    virtual void draw() const ;
    virtual void handle(event);
    void setText(string str);
    void setBadRGB(bool badass);
};

#endif // STATICTEXT_HPP_INCLUDED
