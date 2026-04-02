#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;

};

node* top = nullptr;
void push(int x){
    node* newnode = new node();
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    
}
void pop(){
    if(top ==0){
        cout<<"stack underflow";
        return;
    }
    cout<<top->data<<endl;
    node* temp = top;
    top = top->next ;
    delete temp;


}

void peek(){
    if(top ==0){
        cout<<"stack underflow";
        return;
    }
    cout<<top->data;
}

void display(){
    if(top==0){
        cout<<"stack emnpty";
        return;
    }
    cout<<"stack elements:";
    node* temp = top;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    int choice, val;
    do {
        cout << "\nEnter Choice:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
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