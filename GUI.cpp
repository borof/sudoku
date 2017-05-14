#include "GUI.hpp"
#include "button.hpp"
#include <sstream>

using namespace std;
using namespace genv;

GUI::GUI(){}

void GUI::drawMenu(int &which)
{
    for (int i=0; i < butt.size(); i++)
    {
        butt[i]->draw();
        butt[i]->click(which, ev);
    }
    gout << refresh;
}


void GUI::drawGame()
{
    for (int i=0; i < 9; i++)
    {
        for (int j=0; j < 9; j++)
        {
             butt2[i][j]->draw();
             butt2[i][j]->handle(ev);
        }
    }
    gout << refresh;
}

void GUI::win(){
    gout << move_to(500,300) << color(255,0,0) << text("WIN");
    gout << refresh;
}

GUI::GUI(int widthX, int widthY, string window_name)
{
    wX = widthX;
    wY = widthY;
    title = window_name;
    butt.push_back(new Button(100,100,60,40, "Easy",1));
    butt.push_back(new Button(100,150, 60, 40,"Medium",2));
    butt.push_back(new Button(100,200,60,40,"Hard",3));
    butt.push_back(new Button(300,250,60,40,"Exit",4));
    butt2 = vector <vector<StaticText*> >(9, vector <StaticText*>(9));

   for (int i=0; i < butt2.size(); i++)
    {
        for (int j=0; j < butt2[i].size(); j++)
             butt2[i][j]=(new StaticText(20+40*i,20+40*j+1,40,40,""));

    }
}

void GUI::clearScreen(){
    gout << move_to(0,0) << color(0,0,0) << box(wX, wY) << refresh;
}

void GUI::open()
{
    gout.open(wX,wY);
    gout.set_title(title);
}

void GUI::setEv(event even)
{
    ev = even;
}

void GUI::loadDatas(vector<string> values){
    int k = 0;
    for(int i = 0; i < butt2.size(); i++){
        for( int j=0; j < butt2[i].size(); j++){
            if(values[k] != ""){
                butt2[i][j]->setText(values[k]);
            }
            k++;
        }
    }
}

vector<int> GUI::check(vector<string> values, vector<vector<int> > all){
    vector<int> ind;
    int k = 0;
    if(ev.button == -btn_left){
        for(int i = 0; i < butt2.size(); i++){
            for( int j=0; j < butt2[i].size(); j++){
                if(values[k] == ""){
                    string temp = static_cast<ostringstream*>( &(ostringstream() << all[i][j]) )->str();
                    string temp2 = butt2[i][j]->GetText();
                    if( temp == temp2){
                        butt2[i][j]->setBadRGB(false);
                        butt2[i][j]->setText(temp);
                        ind.push_back(i);
                        ind.push_back(j);
                        return ind;
                    }
                    else if (temp2 != ""){
                        butt2[i][j]->setBadRGB(true);
                    }
                }
                k++;
            }
        }
    }
    return ind;
}
