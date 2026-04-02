#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top =-1;
void push(){
int x;
cout<<"enter data to insert";
cin>>x;
if(top==N-1){
    cout<<"stack overflow";
}
else{
    top++;
    stack[top]=x;

}
}

void pop(){
if(top==-1){
    cout<<"stack underflow";

}
else{
    int item = stack[top];
    top--;
    cout<<item<<endl;
}
}

void peek(){
if(top==-1){
    cout<<"stack empty";

}
else{
    cout<<stack[top]<<endl;
}
}


void display(){
if(top==-1){
    cout<<"stack empty";
}
else{
    cout<<"stack elements are";
    for(int i =top ;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
}

int main(){
    int ch;
    do{
        cout<<"\nEnter the choice:\n" 
        <<"1.Push\n 2.Pop\n 3.Peek \n4.Display\n5.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: push(); 
            break;
            case 2: pop(); 
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