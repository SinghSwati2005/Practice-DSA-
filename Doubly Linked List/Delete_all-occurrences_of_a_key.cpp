
#include<iostream>
using namespace std;

struct node{
    int val;
    node* prev;
    node* next;
    node(int x ): val(x), prev(nullptr), next(nullptr){}
};
node* delete_all_occurrences(node* head, int k){
    node* temp = head;
    while(temp!= NULL){
        if(temp->val == k){
            if(temp==head){
                head = temp->next;
            }
            node* nn = temp->next;
            node* prevNode = temp->prev;
            if(nn!= NULL) nn->prev = prevNode;
            if(prevNode!=NULL) prevNode->next = nn;
            free(temp);
            temp = nn;
        }
        else{
            temp= temp->next;

        }
    }
    return head;
}

void printDLL(node* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}
int main(){
int n , target;
cin>>n>>target;
int val;
    cin >> val;
    node* head = new node(val);
    node* curr = head;

    for(int i =1;i<n;i++){
  cin>>val;
  node* newnode = new node(val);
  curr->next = newnode;
  newnode->prev = curr;
  curr= newnode;
    }
    head = delete_all_occurrences(head,target);
    printDLL(head);
    return 0;
}