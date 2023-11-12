#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <string>
using namespace std;

class dictionary
{
    public:
        dictionary();
        void readWords();
        void printWords();
        void selectionSort();
        void binarySearch();
    private:
        vector<string> words;
};

#endif