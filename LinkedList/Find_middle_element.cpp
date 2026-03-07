#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(0){}

};

ListNode * middleNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != 0 && fast->next!=0){
        slow = slow->next;
        fast = fast->next->next;

    }
    return slow;

}
int main(){
    int n ;
    
    cin>>n;
    if(n<=0){
        cout<<"Empty list"<<endl;
        return 0;
    }
    int val;
    cin>>val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;

    for(int i = 1;i<n;i++){
        cin>>val;
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    ListNode* middle = middleNode(head);
    cout<<middle->val<<endl;
    return 0;
}