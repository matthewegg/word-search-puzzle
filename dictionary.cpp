#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

dictionary::dictionary()
{
    //ctor
}

void dictionary::readWords()
{
    ifstream file;
    file.open("dictionary");
    string word;
    while (file >> word)
    {
        words.push_back(word);
    }
    file.close();
}

void dictionary::printWords()
{
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
}

void dictionary::selectionSort()
{
    int smallestInd;
    int temp;

    for (int firstInd = 0; firstInd < words.size() - 1; firstInd++)
    {
        for (int currInd = firstInd + 1; currInd < words.size() - 1; currInd++)
        {
            if (words[currInd] < words[smallestInd])
                smallestInd = currInd;
        }
        if (smallestInd != firstInd) {
            temp = firstInd;
            words[firstInd] = words[smallestInd];
            words[smallestInd] = temp;
        }
    }
}

// need to add this function, first ask professor what it means for the list of words to be sorted
void dictionary::binarySearch()
{

}