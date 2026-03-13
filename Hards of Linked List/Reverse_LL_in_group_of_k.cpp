#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node* prev;
    node (int x) : val(x), next(nullptr), prev(nullptr){}
};

// check if k node wexists
node* reverseKGroup(node* head , int k){
    node* temp = head;
    int cnt =0;
    while(cnt<k){
        if(temp==0){
          return head; 
        }
        temp = temp->next;
            cnt++;
    }
    node* prevNode = reverseKGroup(temp,k);

    temp = head;
    cnt =0;
    while(cnt<k){
        node* nextNode = temp->next;
        temp->next = prevNode;

        prevNode = temp;
        temp = nextNode;
        cnt++;
    }
    return prevNode;
}


int main() {
    int n, k;
    cin >> n >> k;
    int val;
    cin >> val;
    node* head = new node(val);
    node* curr = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        node* newnode = new node(val);
        curr->next = newnode;
        newnode->prev = curr;
        curr = newnode;
    }

    head = reverseKGroup(head, k);

    // print output
    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
