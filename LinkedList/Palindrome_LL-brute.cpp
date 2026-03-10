#include<iostream>
#include <stack>
using namespace std;
struct node{
    int data ;
    node* next ;
   node (int x) : data(x) , next(nullptr) {}
};

bool isPalindrome(node* head){
    stack <int>st;
    node* temp =head;
    while(temp!= 0){
        st.push(temp->data);
        temp= temp->next;
    }
    temp = head;
    while(temp!=0){
if(temp->data != st.top()){
    return false;
}
st.pop();
temp= temp->next;
    }
    return true;
    
}
int main(){
    int n , val;
    cin>>n>>val;
    node* head = new node(val);
    node* curr= head;
    for(int i =1;i<n;i++){
        cin>>val;
        curr->next =  new node(val);
        curr = curr->next;

    }
    cout<<(isPalindrome(head)? "palindrome": "not palindrome");
    return 0;
}
