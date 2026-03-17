#include<iostream>
#include <vector>
using namespace std;

struct node{
int val;
node* next;
  node* random;

node (int x): val(x),next(nullptr), random(nullptr){}
};

void insertcopyInBetween(node* head){
    node* temp = head;
    while(temp!=NULL){
       
        node* copy = new node(temp->val);

        copy->next = temp->next;
        temp->next = copy;
        temp= copy->next;
    }
}

void connectRandompointers(node* head){
    node* temp = head;
    while(temp!=NULL){
        node* copynode = temp->next;
        if(temp->random){
            copynode->random = temp->random->next;
        }
        else{
            copynode->random = NULL;
        }
        temp = temp->next->next;
    }
}

node* getDeepCopyList(node* head){
    node* dummy = new node(-1);
    node* copytail = dummy;
    node* temp = head;
    while(temp){
        node* copy = temp->next;
        copytail->next =copy;
        copytail = copy;

        temp->next = copy->next;
        temp = temp->next;

    }
    return dummy->next;
}



node* cloneLL(node* head){
if(!head) return NULL;

insertcopyInBetween(head);

connectRandompointers(head);
return getDeepCopyList(head);
}

void printClonedLinkedList(node* head) {
    while (head) {
        cout << "Data: " << head->val;
        if (head->random) cout << ", Random: " << head->random->val;
        else cout << ", Random: nullptr";
        cout << endl;
        head = head->next;
    }
}


int main(){
    int n;
    cin>>n;
    vector<node*>nodes;
    for(int i =0;i<n;i++){
    int val;
    cin>>val;
    
    nodes.push_back(new node(val));
    if(i>0) nodes[i-1]->next = nodes[i];

    
}

for(int i =0;i<n;i++){
    int idx;
    cin>>idx;
    if(idx!= -1) nodes[i]->random = nodes[idx];

}

node* head = nodes[0];
node* clonedHead = cloneLL(head);
printClonedLinkedList(clonedHead);
return 0;
}