#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

   Node(int x) : data(x), next(nullptr){}
    
};

int countLoopLength(Node* meetingPoint){
    Node* temp = meetingPoint;
    int length = 1;

    while(temp->next != meetingPoint){
        temp = temp->next;
        length++;
    }
    return length;
}


int lengthOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!= nullptr && fast->next != nullptr){
        slow = slow->next;
        fast= fast->next->next;

        if(slow==fast){
            return countLoopLength(slow);
        }
    }
    return 0;
}



int main(){
    int n;
    cin>>n;
    int val;
    cin>>val;

    Node* head = new Node(val);
    Node* curr = head;

    for(int i =1;i<n;i++){
        cin>>val;

        curr->next = new Node(val);
        curr =  curr->next;
    }

    curr->next = head->next->next;

    cout<< lengthOfLoop(head)<<endl;
    return 0;
}
