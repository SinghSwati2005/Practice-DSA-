#include <iostream>
#include <stack>
using namespace std;

stack<int> st1, st2;

// Enqueue (push into queue)
void enqueue(int x) {
    // Move all elements from st1 to st2
    while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }

    // Push new element into st1
    st1.push(x);

    // Move everything back to st1
    while (!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
    }

    cout << x << " enqueued into queue." << endl;
}

// Dequeue (pop from queue)
void dequeue() {
    if (st1.empty()) {
        cout << "Queue Underflow!" << endl;
        return;
    }
    int x = st1.top();
    st1.pop();
    cout << "Dequeued: " << x << endl;
}

// Peek front element
void peek() {
    if (st1.empty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Front element: " << st1.top() << endl;
}

// Display all elements
void display() {
    if (st1.empty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    stack<int> temp = st1;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\nEnter Choice:\n"
             << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
