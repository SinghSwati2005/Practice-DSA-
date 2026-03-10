#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public :
    int val;
    ListNode * next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution{
    public : 
    ListNode* oddEvenList(ListNode* head){
        if(head == nullptr || head->next==nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        while(even!= 0 && even->next!=0){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;

        }
        odd->next = evenhead;
        return head;
    }


};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}


int main(){
    int n;
    cin>>n;
    int val;
    cin>>val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next = new ListNode(val);
 curr = curr->next;
    }
    Solution sol;
    printList(sol.oddEvenList(head));
    return 0;
   

}


