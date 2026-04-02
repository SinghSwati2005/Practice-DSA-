#include<iostream>
#include<queue>
using namespace std;
class Stack{
queue<int>q1,q2;
public:
void push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);

}
void pop(){
    if(q1.empty()){
        cout<<"Stack underflow";
        return;
    }
    cout<<"popped"<<q1.front();
    q1.pop();
}

void topelement(){
    if(q1.empty())
 {   cout<<"stack is emty";
    return;
}
cout<<"top element"<<q1.front()<<endl;
}


void display(){
    if(q1.empty()){
        cout<<"stack empty";
        return;
    }
    cout<<"stack elmnt:";
    queue<int>temp = q1;
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }

}

};


int main(){
    Stack st;
    int choice , val;
    do{
cout << "\nEnter Choice:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.topelement();
                break;
            case 4:
                st.display();
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


