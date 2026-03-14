#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;
    node* prev;
    node (int x) : val(x), next(nullptr), prev(nullptr){}
};





    // Function to rotate the linked list to the right by k places
    node* rotate(node* head, int k) {
        // If list is empty or has only one node, or no rotation is needed
        if (!head || !head->next || k == 0)
            return head;

        // Initialize length and tail pointer
        int length = 1;
        node* tail = head;

        // Traverse to find the tail and length
        while (tail->next) {
            tail = tail->next;
            length++;

        }

        // Make it a circular linked list
        tail->next = head;

        // Effective rotations needed
        k = k % length;

        // Traverse to the new tail (length - k - 1 steps from head)
        int stepsToNewTail = length - k;
        node* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;

        }

        // Set the new head
        node* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }



node* printLL(node* head){
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

    for(int i =1;i<n;i++){
        cin>>val;
        node* newnode = new node(val);
        curr->next = newnode;
        newnode->prev = curr;
        curr = newnode;
    }
    head = rotate(head,k);
    printLL(head);
    return 0;
}
