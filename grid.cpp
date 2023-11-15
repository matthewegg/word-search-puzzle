#include "grid.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

grid::grid()
{
    //ctor
}

void grid::readGrid(string fileName)
{
    ifstream file;
    string line;

    while (getline(file, line))
    {
        vector<char> row(line.begin(), line.end());
        matrix.push_back(row);
    }
    
    file.close();
}