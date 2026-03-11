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
    
    node* intersection(node* head1, node* head2){
      node* d1 = head1;
      node* d2= head2;
      while(d1!=d2){
        d1 = d1==nullptr ? head2 : d1->next;
        d2 = d2==nullptr? head1 : d2->next;
      }
      return d1;
       
       

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