#include <iostream>
#include <stack>
using namespace std;

stack<int> input, output;

// Enqueue (push into queue)
void enqueue(int x) {
    input.push(x);
    cout << x << " enqueued into queue." << endl;
}

// Dequeue (pop from queue)
int dequeue() {
    if (output.empty()) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    if (output.empty()) {
        cout << "Queue is empty, cannot pop." << endl;
        return -1;
    }
    int x = output.top();
    output.pop();
    cout << "Dequeued: " << x << endl;
    return x;
}

// Peek front element
void peek() {
    if (output.empty()) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    if (output.empty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Front element: " << output.top() << endl;
}

// Display all elements
void display() {
    if (output.empty()) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    if (output.empty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    stack<int> temp = output;
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
