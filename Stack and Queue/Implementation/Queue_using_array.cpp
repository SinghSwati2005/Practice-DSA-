#include<iostream>
using namespace std;
#define N 5

int queue[N];
int front = -1;
int rear = -1;
void enqueue(){
    int x;
    cout<<"\nenter data :";
    cin>>x;
    if(rear ==N-1){
        cout<<"queue overflow";
    }
    else if(front ==-1 && rear == -1){
        front = rear =0;
        queue[rear] =x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front ==-1 && rear==-1){
        cout<<"queue underflow";
    }
    else if(front == rear){
        front = rear =-1;
    }
    else{
        cout<<queue[front];
        front++;
    }
}

void peek(){
if(front ==-1 &&rear==-1){
    cout<<"queue empty";
}
else{
    cout<<queue[front];
}
}
void display(){
int i;
if(front==-1 && rear==-1){
    cout<<"queue is empty";
}
else{
    for(int i = front ; i<rear;i++){
        cout<<queue[i];
    }
}
}

int main(){
    int ch;
    do{
        cout<<"\nEnter the choice:\n" 
        <<"1.Push\n 2.Pop\n 3.Peek \n4.Display\n5.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: enqueue(); 
            break;
            case 2: dequeue(); 
            break;
            case 3: peek(); 
            break;
            case 4: display(); 
            break;
            case 5: cout<<"Exiting....."<<endl; 
            break;
            default : cout<<"Invalid Choice!!"<<endl;
        }

    } while(ch!=5);
    return 0;
}