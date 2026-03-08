#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next =nullptr;
    }
};

ListNode* detectCycles(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast ->next->next;
        if(slow==fast){
            slow = head;
        
        while(slow!= fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
}
return nullptr;
}
int main(){
    int n , val;
    cin>>n>>val;

    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    for(int i=1;i<n;i++){
        cin>>val;
        curr->next = new ListNode(val);
        curr= curr->next;
    }
   curr->next = head->next;
    ListNode* cycleStart = detectCycles(head);
    if(cycleStart!= nullptr)
        cout<<cycleStart->val<<endl;
        else  
            cout<<-1<<endl;
            return 0;

}