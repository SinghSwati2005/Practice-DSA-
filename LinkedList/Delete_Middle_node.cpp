#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node (int x): val(x), next(nullptr){}

};

class Solution{
    public:
      node* delete_mid(node* head){
        node* slow = head;
        node* fast = head->next->next;
        while(fast!=0 && fast->next!=0){
            slow = slow->next;
            fast = fast->next->next;

        }

        node* mid = slow->next;
        slow->next = slow->next->next;
        delete mid;
        return head;

      }
};

void printLL(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int n ;
    int val;
    cin>>n>>val;

    node* head = new node(val);
    node* curr = head;
    for(int i = 1;i<n;i++){
        cin>>val;
        curr->next = new node(val);
        curr = curr->next;
    }

    Solution sol;
    printLL(sol.delete_mid(head));


}