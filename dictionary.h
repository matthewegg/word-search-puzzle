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
        void printWords() const;
        void selectionSort();
        bool binarySearch(string word) const;
    private:
        vector<string> words;
};

#endif