
#include<iostream>
#include<vector>
using namespace std;

struct node{
int val;
node* next ; node* prev;
node (int x) : val(x) , next(nullptr), prev(nullptr){}
};

void helper(node* nn, node* prevNode){
      if (!nn) return;
   
   

    prevNode->next = nn->next;
    if(nn->next){
 nn->next->prev = prevNode;
    }
   
    
    delete nn;
   
   }

node* duplicate(node* head){
    node* temp = head;
    while(temp->next!=0){
        if(temp->val==temp->next->val){
            helper(temp->next,temp);
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
int main(){
    int n ;
    cin>>n;
    int val;
    cin>>val;
    node* head = new node(val);
    node* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        node* newnode = new node(val);
        curr->next = newnode;
        newnode->prev = curr;
        curr = newnode;
    }

    head = duplicate(head);
       curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
  return 0;
}