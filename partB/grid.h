#ifndef GRID_H
#define GRID_H
#include <vector>
#include <string>
using namespace std;

class grid
{
    public:
        grid();
        void readGrid(string);
        vector<vector<char>> getMatrix();
    private:
        vector<vector<char>> matrix;
};

#endif