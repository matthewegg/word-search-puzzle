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

int dictionary::getDictSize() const
{
    return words.size();
}

void dictionary::selectionSort()
{
    for (int firstInd = 0; firstInd < words.size() - 1; firstInd++)
    {
        int smallestInd = firstInd;
        for (int currInd = firstInd + 1; currInd < words.size(); currInd++)
        {
            if (words[currInd] < words[smallestInd])
                smallestInd = currInd;
        }
        if (smallestInd != firstInd) {
            std::swap(words[firstInd], words[smallestInd]);
        }
    }
}

bool dictionary::binarySearch(string word) const
{
    int first = 0;
    int last = size(words) - 1;

    while (first <= last)
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

void dictionary::quickSort(int first, int last)
{
    if (first < last)
    {
        int pivot = partition(first, last);
        quickSort(first, pivot - 1);
        quickSort(pivot + 1, last);
    }
}

int dictionary::partition(int first, int last)
{
    string pivot = words[last];
    int i = first - 1;

    for (int j = first; j < last; j++)
    {
        if (words[j] < pivot)
        {
            i++;
            swap(words[i], words[j]);
        }
    }

    swap(words[i + 1], words[last]);
    return i + 1;
}