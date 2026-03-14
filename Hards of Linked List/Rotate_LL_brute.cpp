#include<iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node* prev;
    node (int x): val(x),next(nullptr),prev(nullptr){}
};

node* rotate(node* head , int k){
    while(head==NULL || head->next== NULL) return head;
  for(int i =0;i<k;i++){

  
    node* temp = head;
    node* prev= NULL;
    while(temp->next !=NULL){
        prev = temp;
        temp= temp->next;
       
    }
    prev->next = NULL;
    temp->next = head;
    head = temp;
}

return head;
}


void printLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;

    }
    cout<<endl;
}


int main(){
    int n,k;
    cin>>n>>k;
    int val;
    cin>>val;
    node* head = new node(val);
    node* curr = head;
   

    for(int i =1 ;i<n;i++){
        cin>>val;
        node* newnode = new node(val);
        curr->next = newnode;
        newnode->prev = curr;
        curr=  newnode;


    }

    head = rotate(head,k);

    printLL(head);
    return 0;

}
