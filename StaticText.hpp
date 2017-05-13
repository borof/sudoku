#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;
using namespace std;

class StaticText : public Widget{
    //bool _selected;
    string _text;
public:
    string GetText (){return _text;}

    StaticText(int,int,int,int,string);
    virtual void draw() const ;
    virtual void handle(event);
};

/**
hazi:
Lehessen hozza irni, backspace-szel torolni.
Tobb eseten a kivalasztottal lehet dolgozni.
Kurzor a vegen jelzi, hogy melyikbe irsz. (crtl+w = kurzor)

**/

#endif // STATICTEXT_HPP_INCLUDED
