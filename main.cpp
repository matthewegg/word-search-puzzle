#include "dictionary.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void findMatches(dictionary dict, grid grid)
{
    /* thinking about the logic:
    - need to search left, right, up down from word lengths 5 to full dimension length of the board
    - diagonals have the same word length limits and there are four of them
    */
}