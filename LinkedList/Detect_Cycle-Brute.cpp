#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int val;
    Node* next ;
    Node(int x):val(x) , next(nullptr){}
};
bool detectLoop(Node* head){
    Node* temp= head;
    unordered_map<Node* , int>mpp;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end());
        {
            return true;
        }
        mpp[temp]= 1;
        temp = temp->next;
    }
    return false;
}
int main(){
    int n , val;
    cin>>n>>val;
    Node * head = new Node(val);
    Node* curr = head;
    for(int i=1;i<n;i++){
        cin>>val;
        curr->next = new Node(val);
        curr = curr->next;
    }

    // curr->next = head->next;

    if(detectLoop(head)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;

}