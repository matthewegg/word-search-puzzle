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

void dictionary::printWords() const
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

bool dictionary::binarySearch(string word) const
{
    int first = 0;
    int last = size(words) - 1;

    while (first != last)
    {
        string str = words[(first + last) / 2];
        if (str == word)
        {
            return true;
        }
        else if (word < str)
        {
            last = ((first + last) / 2) - 1;
        }
        else
        {
            first = ((first + last) / 2) + 1;
        }
    }

    return false;
}