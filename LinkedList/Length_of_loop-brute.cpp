#include<iostream>
#include <unordered_map>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr){}
};

int findlength(Node* head){
   unordered_map<Node*,int> mpp;
   Node* temp = head;
   int cnt =0;
   while(temp!=0){
    if(mpp.find(temp) != mpp.end()){
        int looplength = cnt- mpp[temp];
        return looplength;
    }
    mpp[temp] = cnt;
    temp= temp->next;
    cnt++;
   }
   return 0;

}



int main(){
    int n , val;
    cin>>n>>val;
    Node* head = new Node(val);
    Node* curr = head;

    for(int i=1;i<n;i++){
        cin>>val;
        curr->next = new Node(val);
        curr = curr->next;
    }
    curr->next = head->next->next;
    cout<<findlength(head)<<endl;
    return 0;

}