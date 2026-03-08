#include<iostream>
#include<unordered_map>
using namespace std;


struct Node{
    int val;
    Node* next;
    Node(int x):val(x) , next(nullptr){}
};
bool detectCycles(Node* head){
  Node* temp = head;
  Node* slow = head;
  Node* fast = head;
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast= fast->next->next;
    if(slow == fast){
        return true;
    }
  }
  return false;
}

int main(){
    int n , val;
    cin>>n>>val;
    Node* head = new Node(val);
    Node* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next = new Node(val);
        curr = curr->next;
        
    }
curr->next = head->next;
    cout << (detectCycles(head) ? "Loop detected" : "No loop") << endl;

    return 0;
}