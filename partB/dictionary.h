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
        int getDictSize() const;
        void selectionSort();
        void quickSort(int, int);
        int partition(int, int);
        bool binarySearch(string word) const;
    private:
        vector<string> words;
};

#endif