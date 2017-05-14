#include "GUI.hpp"
#include "button.hpp"

using namespace std;
using namespace genv;

GUI::GUI(){}

void GUI::drawMenu(int &which)
{
    Button * button1 = new Button(100,100,60,40, "Easy",1);
    Button * button2 = new Button(100,150, 60, 40,"Medium",2);
    Button * button3 = new Button(100,200,60,40,"Hard",3);
     Button * exit = new Button(300,250,60,40,"Exit",4);

    button1->draw();
    button2->draw();
    button3->draw();
    exit->draw();

    button1->click(which);
    button2->click(which);
    button3->click(which);
    exit->click(which);
    gout << refresh;
}


GUI::GUI(int widthX, int widthY, std::string window_name){
    wX = widthX;
    wY = widthY;
    title = window_name;
}

void GUI::open(){
    gout.open(wX,wY);
    gout.set_title(title);
}

event GUI::getEv() const{
    return ev;
}

