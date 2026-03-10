#include<iostream>
using namespace std;
struct node{
    int data;
    node* next ;
    node(int x): data(x), next(nullptr){}
};

node* reverseList(node* head){
    node* prev = nullptr;
    node* curr = head;
    while(curr!=0){
        node* nn = curr->next;
        curr->next = prev;
        prev = curr;
        curr= nn;
    }
    return prev;
}

bool isPalindrom(node* head){
    if(head == nullptr || head ->next == nullptr) return true;
    node* slow = head;
    node* fast = head;
    while(fast->next!= 0 && fast->next->next!=0){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* secondHalf = reverseList(slow->next);

    node* firsthalf = head;
    
    bool palindrome = true;
    while(secondHalf != 0){
        if(firsthalf->data!= secondHalf->data){
            palindrome = false;
            break;
        }
        firsthalf = firsthalf->next;
        secondHalf= secondHalf->next;
    }
    slow ->next = reverseList(secondHalf);
    return palindrome;
}

int main(){
    int n ;
    cin>>n;
    if(n<=0) return 0;
    int val ;
    cin>>val;
    node* head = new node(val);
    node* curr = head;
    for(int i=1;i<n;i++){
        cin>>val;
        curr->next = new node(val);
        curr= curr->next;
    }
    cout<<(isPalindrom(head)?"true":"false");
    return 0;
}