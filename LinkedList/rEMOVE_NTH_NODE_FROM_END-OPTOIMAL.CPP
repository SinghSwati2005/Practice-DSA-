#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x): val(x),next(nullptr){}
};

class Solution{
    public:
    node* remove_from_last(node* head, int n){
    node* dummy = new node(0);
    dummy->next = head;
    node* slow = dummy;
    node* fast = dummy;
    for(int i=0;i<=n;i++){
        fast = fast->next;

    }

    while(fast != nullptr){
      
        fast= fast->next;
          slow = slow->next ;
    }
    slow ->next = slow->next->next;
    return dummy->next;

    }
};

void printList(node* head){
    while(head){
        cout<<head->val;
        if(head->next ) cout<<"->";
        head = head->next;
    }
    cout<<"-> NULL";
}
int main(){
    int n , k;
    cin>>n>>k;
    int val;
    cin>>val;
    node* head = new node(val);
    node* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next = new node (val);
        curr = curr->next;

    }
    Solution sol;
    printList(sol.remove_from_last(head,k));
}