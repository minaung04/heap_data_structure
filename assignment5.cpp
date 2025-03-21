#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int deleteRoot() {
        if (heap.empty()) return -1;
        if (heap.size() == 1) {
            int root = heap.back();
            heap.pop_back();
            return root;
        }
        
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap;
    vector<int> values = {10, 40, 30, 20, 50, 60, 70};

    cout << "Inserting values into the heap:" << endl;
    for (int v : values) {
        heap.insert(v);
        heap.display();
    }

    cout << "\nRemoving elements from the heap:" << endl;
    while (true) {
        int deletedValue = heap.deleteRoot();
        if (deletedValue == -1) break;
        cout << "Deleted: " << deletedValue << endl;
        heap.display();
    }

    return 0;
}

