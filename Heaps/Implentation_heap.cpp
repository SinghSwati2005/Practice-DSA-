#include <bits/stdc++.h>
using namespace std;

class BinaryHeap {
public:
    int capacity;  
    int size;  
    int* arr;  

    BinaryHeap(int cap) {
        capacity = cap;  
        size = 0;  
        arr = new int[capacity];  
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void Insert(int x) {
        if (size == capacity) {
            cout << "Binary Heap Overflow" << endl;
            return;
        }
        arr[size] = x;
        int k = size;
        size++;
        while (k != 0 && arr[parent(k)] > arr[k]) {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    void Heapify(int ind) {
        int li = left(ind), ri = right(ind);
        int smallest = ind;
        if (li < size && arr[li] < arr[smallest]) smallest = li;
        if (ri < size && arr[ri] < arr[smallest]) smallest = ri;
        if (smallest != ind) {
            swap(&arr[ind], &arr[smallest]);
            Heapify(smallest);
        }
    }

    int getMin() { return (size > 0) ? arr[0] : INT_MAX; }

    int ExtractMin() {
        if (size <= 0) return INT_MAX;
        if (size == 1) { size--; return arr[0]; }
        int mini = arr[0];
        arr[0] = arr[size - 1];
        size--;
        Heapify(0);
        return mini;
    }

    void Decreasekey(int i, int val) {
        arr[i] = val;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i) {
        Decreasekey(i, INT_MIN);
        ExtractMin();
    }

    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void print() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int cap, n;
    cout << "Enter heap capacity: ";
    cin >> cap;
    BinaryHeap h(cap);

    cout << "Enter number of elements to insert: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        h.Insert(val);
    }

    cout << "Heap after insertion: ";
    h.print();
    cout << "Min value is " << h.getMin() << endl;

    // Example interactive operations
    cout << "Extracting min: " << h.ExtractMin() << endl;
    cout << "Heap after extract: ";
    h.print();

    int idx, newVal;
    cout << "Enter index and new value for DecreaseKey: ";
    cin >> idx >> newVal;
    h.Decreasekey(idx, newVal);
    cout << "Heap after DecreaseKey: ";
    h.print();

    cout << "Deleting element at index 0..." << endl;
    h.Delete(0);
    cout << "Heap after delete: ";
    h.print();

    return 0;
}
