#include<iostream>
using namespace std;


struct node{
    int data;
    node*  next;

};

node* front = nullptr;
node* rear = nullptr;

void enqueue(int x){
    node* newnode = new node();
    newnode->data = x;
  newnode->next = nullptr;

  if(rear == nullptr){
    front = rear = newnode;

  }
  else{
    rear->next = newnode;
    rear = newnode;
  }
  cout<<x<<"enequeued into queue"<<endl;



}


void dequeue(){
    if(front == nullptr){
        cout<<"queue underflow"<<endl;
    }
    node* temp = front;
    front = front->next;
    if(front == nullptr){
        rear = nullptr;
    }
    delete temp;

}

void peek(){
    if(front==nullptr){
        cout<<"queue empty"<<endl;

    }
    cout<<"front element "<<front->data<<endl;
}

void display(){
    if(front == nullptr){
        cout<<"queue is empty"<<endl;

    }
    cout<<"queue elements";
    node* temp = front;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
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