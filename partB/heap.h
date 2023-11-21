#ifndef HEAP_H
#define HEAP_H
#include <vector>
using namespace std;

template <typename T>
class heap {
    vector<T> objects;
    public:
        heap() {}
        int parent(int i) const {
            return i/2;
        }

        int left(int i) const {
            return 2*i;
        }

        int right(int i) const {
            return 2*i + 1;
        }

        T getItem(int n) const {
            return objects[n];
        
        }

        void initializeMaxHeap() {
            for (int i = objects.size() / 2; i >= 1; --i) {
                maxHeapify(i);
            }
        }

        void maxHeapify(int i) {
            int largest = i;
            int l = left(i);
            int r = right(i);
        
            if (l < objects.size() && getItem(l) > getItem(largest)) {
                largest = l;
            }
            if (r < objects.size() && getItem(r) > getItem(largest)) {
                largest = r;
            }
            if (largest != i) {
                swap(objects[i], objects[largest]);
                maxHeapify(largest);
            }
        }

        void buildMaxHeap() {
            initializeMaxHeap();
        }

        void heapsort() {
            buildMaxHeap();
            for (int i = objects.size() - 1; i >= 2; --i) {
                swap(objects[1], objects[i]);
                objects.pop_back();
                maxHeapify(1);
            }
        }

        void push(T item) {
            objects.push_back(item);
        }
};

#endif