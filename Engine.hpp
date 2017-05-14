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

    std::vector<Coord> coordinates;
    std::vector< std::vector<int> > everyNumber;
    std::vector<int> feedback;

public:
    Engine();
    int getFeedback(int number, int x, int y);
    void setEveryNumber(std::vector<std::vector<int> > configFile);
    void setEmptyNumber(std::vector<int> row, std::vector<int> col);
};

#endif // ENGINE_HPP_INCLUDED
