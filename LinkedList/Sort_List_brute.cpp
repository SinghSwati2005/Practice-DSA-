#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct node{
    int val;
    node* next;
    node(int x): val(x), next(nullptr){}
};

node* sort_list(node* head){
    vector<int>nums;
    node* temp = head;
    while(temp!=nullptr){
        nums.push_back(temp->val);
        temp= temp->next;
    }
    sort(nums.begin(),nums.end());

    temp = head;
    for(int i =0;i<nums.size();i++){
        temp->val = nums[i];
        temp= temp->next;
    }
    return head;
}

void printLinkedList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int n , val;
    cin>>n>>val;
    node* head = new node(val);
    node* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next =  new node(val);
        curr = curr->next;

        
        
    }
    head = sort_list(head);
    printLinkedList(head);

}