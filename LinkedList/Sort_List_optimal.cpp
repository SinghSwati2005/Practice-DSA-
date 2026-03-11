#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node(int x):val(x), next(nullptr){}
};

class Solution{
    public:
    node* mergesortList(node* l1 , node* l2){
        node* dummy = new node(-1);
        node* temp = dummy;
        while(l1!= nullptr && l2!= nullptr){
            if(l1->val<=l2->val){
                temp->next = l1;
                l1= l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;

            }
            temp = temp->next;
        }

        if(l1!= nullptr){
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }
        return dummy->next;
    }


    node* mid(node* head){
        if(head==nullptr || head->next == nullptr) return head;
        node* slow = head;
        node* fast = head->next;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    node* sortLL(node* head){
   if(head==nullptr || head->next == nullptr) return head;

   node* middle = mid(head);
node* right = middle->next;
middle->next = nullptr;
node* left = head;

left = sortLL(left);
right = sortLL (right);

return mergesortList(left,right);
    }
};

void printLL(node* head){
    node* temp = head;
    while(temp!= nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;

    }
}

int main(){
    int n ;
    cin>>n;
    int val;
    cin>>val;
    node* head = new node(val);
    node* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next = new node(val);
        curr = curr->next;
    }

    Solution sol;
    head = sol.sortLL(head);
     cout << "Sorted list: ";
    printLL(head);
    return 0;

}