#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node(int x): val(x) , next(nullptr){}
};

node* remove_nth_node_from_end(node* head, int n){
int len =0;
node*  temp = head;
while(temp!= nullptr){
    len++;
    temp = temp->next;
}
int pos = len -n;
if(pos ==0){
    node* newhead = head->next;
    delete head;
    return newhead;
}

node* prev = head;
for(int i=1;i<pos;i++){
    prev = prev->next;

}

node* target = prev->next;
prev->next = target->next;
delete target;
return head;

}

void printList(node* head){
    while(head!= nullptr){
        cout<<head->val;
        if(head->next) cout<<"->";
        head = head->next;

    }
    cout<<"->NULL"<<endl;
}

int main(){
    int n , k,val;
    cin>>n>>k>>val;
    node* head = new node(val);
    node* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next = new node(val);
        curr = curr->next;
    }
    printList(remove_nth_node_from_end(head,k));
    return 0;
}