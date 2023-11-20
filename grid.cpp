#include "grid.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

grid::grid()
{
    //ctor
}

void grid::readGrid(string fileName)
{
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open file" << endl;
        return;
    }

    string line;
    if (!getline(file, line) || line.empty()) {
        cout << "File is empty" << endl;
        return;
    }

    while (getline(file, line)) {
        vector<char> row;
        for (char ch : line) {
            if (!isspace(ch) && isalpha(ch)) {
                row.push_back(ch);
            }
        }
        matrix.push_back(row);
}

    file.close();
}

vector<vector<char>> grid::getMatrix()
{ 
    return matrix;
}