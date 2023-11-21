#include "dictionary.h"
#include "grid.h"
#include "heap.h"
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
                        // Calculate the next character's coordinates considering the wrap-around
                        int nextRow = (i + dir.first * k + rows) % rows;
                        int nextCol = (j + dir.second * k + cols) % cols;
                        word += grid.getMatrix()[nextRow][nextCol];
                    }
                    if (dict.binarySearch(word)) {
                        cout << word << endl;
                    }
                }
            }
        }
    }
}


void search(int i)
{
    cout << "Search entered" << endl << endl;
    string gridFile;
    dictionary dict;
    grid grid;

    cout << "Enter the name of the grid to be used: ";
    cin >> gridFile;

    dict.readWords();
    grid.readGrid(gridFile);

    if (i == 1) {
        dict.selectionSort();
    }
    else if (i == 2) {
        cout << "Quick sort" << endl;
        dict.quickSort(0, dict.getDictSize() - 1);
    }
    else if (i == 3) {
        cout << "Heap sort" << endl;
        dict.heapSort();
    }
    else {
        cout << "Invalid input" << endl;
        return;
    }

    findMatches(dict, grid);

}

int main() {
    int i;
    cout << "Enter 1 for selection sort, 2 for quick sort, 3 for heap sort: ";
    cin >> i;
    cout << "Entering search..." << endl << endl;
    search(i);
    cout << endl << "Exiting search..." << endl;
    return 0;
}