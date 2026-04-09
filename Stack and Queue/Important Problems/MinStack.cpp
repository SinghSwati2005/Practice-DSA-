#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}

    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // sentinel value
        }
        return st.top().second;
    }

    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
            return;
        }
        int mini = min(getMin(), value);
        st.push({value, mini});
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        st.pop();
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // sentinel value
        }
        return st.top().first;
    }
};

int main() {
    MinStack s;
    int choice, value;

    cout << "MinStack Operations Menu:\n";
    cout << "1. Push\n2. Pop\n3. Top\n4. GetMin\n5. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.top() << endl;
                break;
            case 4:
                cout << "Minimum element: " << s.getMin() << endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}
