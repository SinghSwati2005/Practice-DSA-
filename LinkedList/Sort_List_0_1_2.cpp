#include<iostream>
using namespace std;
struct node{
    int val;
    node* next ;
    node(int x): val(x), next(nullptr){}
};

class Solution{
    public:
    node* sortLL(node* head){
        node* zero = new node(-1);
        node* one = new node(-1);
        node* two = new node(-1);

        node* zeroTail = zero;
        node* oneTail = one;
        node* twoTail = two;

        node* temp = head;
        while(temp!= nullptr){
            if(temp->val==0){
                zeroTail->next = temp;
                zeroTail = zeroTail->next;
            }
            else if ( temp->val == 1){
                oneTail->next = temp;
                oneTail = oneTail->next;
            }
            else{
                twoTail->next= temp;
                twoTail = twoTail->next;
            }
            temp = temp->next;
        }

       zeroTail->next = one->next ? one->next : two->next;
       oneTail->next = two->next;
       twoTail = nullptr; 

       node* newHead = zero->next;
       delete zero;
       delete one;
       delete two;
       return newHead;

    }

};
void printLL(node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int val;
    cin >> val;
    node* head = new node(val);
    node* curr = head;
    for (int i = 1; i < n; i++) {
        cin >> val;
        curr->next = new node(val);
        curr = curr->next;
    }

    Solution sol;
    head = sol.sortLL(head);
    cout << "Sorted list: ";
    printLL(head);
    return 0;
}