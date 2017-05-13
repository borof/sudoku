#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;
using namespace std;

class StaticText : public Widget{

    string _text;
public:
    string GetText (){return _text;}

    StaticText(int,int,int,int,string);
    virtual void draw() const ;
    virtual void handle(event);
};

#endif // STATICTEXT_HPP_INCLUDED
