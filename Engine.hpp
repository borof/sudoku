#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED
#include <vector>

class Engine{

private:
   struct Coord
    {
        int x = 0;
        int y = 0;
    };

    vector<Coord> coordinates;
    vector< vector<int> > everyNumber(9, vector<int>(9));
    vector<int> feedback;

public:
    Engine();
    int getFeedback(int x, int y);

};

#endif // ENGINE_HPP_INCLUDED
