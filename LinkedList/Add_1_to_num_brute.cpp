#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node (int x) : val(x), next(nullptr){}
};

node* reverseList(node* head){
    node* temp= head;
    node* curr = head;
    node* prev = 0;

    while(curr!=nullptr){
        node* nn = curr->next;
       curr->next = prev;
       prev = curr;
       curr= nn;
      
    }
    return prev;
}

node* Add1(node* head){
    head = reverseList(head);
    node* temp = head;
    int carry =1;
   

    while(temp!= nullptr){
       temp->val += carry;
       if(temp->val <10){
        carry =0;
        break;
       }
       else{
        temp->val = 0;
        carry = 1;
       }
      // temp = temp->next;
    
    if(temp->next == nullptr &&carry ==1){
       temp->next = new node(1);
            carry = 0;
            break;
    }
     temp = temp->next;
}
 head = reverseList(head);

    return head;
}

void printLL(node* head){
    node* temp = head;
    while(temp!= nullptr){
        cout<<temp->val;
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n ;
    cin>>n;
    int val;
    cin>>val;

    node* head = new node(val);
    node* curr= head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next = new node(val);
        curr = curr->next;
    }
  head = Add1(head);
  printLL(head);
    return 0;
}


// O(3n) - time complexity 2 for reverse one for traversal