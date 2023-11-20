#include "dictionary.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void findMatches(dictionary dict, grid grid)
{
    int rows = grid.getMatrix().size();
    int cols = grid.getMatrix()[0].size();
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (auto& dir : directions) {
                for (int len = 5; len <= max(rows, cols); ++len) {
                    string word = "";
                    for (int k = 0; k < len; ++k) {
                        // Calculate the next cell's coordinates considering the wrap-around
                        int nextRow = (i + dir.first * k + rows) % rows;
                        int nextCol = (j + dir.second * k + cols) % cols;
                        word += grid.getMatrix()[nextRow][nextCol];
                    }
                    //cout << "Testing word: " << word << endl;
                    if (dict.binarySearch(word)) {
                        cout << word << endl;
                    }
                }
            }
        }
    }
}

int main() {
    dictionary dict;
    grid grid;

    dict.readWords();
    dict.selectionSort();
    grid.readGrid("input15");
    grid.getMatrix();

    findMatches(dict, grid);
}