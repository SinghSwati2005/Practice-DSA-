#include<iostream>
#include<unordered_set>
using namespace std;
struct node{
    int val;
    node* next;
    node (int x) : val(x) , next(nullptr){}
};

class Solution{
    public:
    int getLength(node* head){
        node* temp = head;
        int len = 0;
        while(temp!= nullptr){
            len++;
            temp = temp->next;
        }
        return len;
    }
    node* intersection(node* head1, node* head2){
       int len1 = getLength(head1);
       int len2 = getLength(head2);

       int diff = abs(len1-len2);
       if(len1>len2){
        for(int i =0;i<diff;i++){
            head1 = head1->next;
        }
    }
        else {
                for(int i = 0;i<diff;i++){
            head2= head2->next;
        }
    }

    while(head1!= nullptr && head2!= nullptr){
        if(head1== head2) return head1;
         head1 = head1->next;
            head2 = head2->next;
    }
    return nullptr;
       
       

    }
};
int main(){
    int n ; 
    int m;
    cin>>n>>m;
    int val;
    cin>>val;
    node* head1 = new node(val);
    node* curr1 = head1;
    node* head2 = new node(val);
    node* curr2 = head2;

    for(int i =1;i<n;i++){
        cin>>val;
        curr1->next = new node(val);
        curr1= curr1->next;
    }
    cin>>val;
    for(int i =1;i<m;i++){
        cin>>val;
        curr2->next = new node(val);
        curr2= curr2->next;
    }

  
    curr2->next = head1->next->next->next;

      Solution sol;
      node* ans = sol.intersection(head1,head2);
      if(ans) cout<<ans->val<<endl;
      else
      nullptr;
      
}