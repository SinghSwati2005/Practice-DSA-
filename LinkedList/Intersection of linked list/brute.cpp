#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node (int x) : val(x), next(nullptr){}
};

class Solution{
    public:
    node* intersection(node* head1 , node* head2){
     
        while(head2!=nullptr){
               node* temp = head1;
            while(temp!= nullptr){
                if(temp == head2) return head2;
                temp= temp->next;
            }
            head2= head2->next;
        }
        return nullptr;
    }
};
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int val;
    cin>>val;
    node* head1 = new node(val);
    node* curr1 = head1;
    node* head2 = new node(val);
    node* curr2= head2;

    for(int i = 1;i<n;i++){
        cin>>val;
        curr1->next = new node(val);
        curr1 = curr1->next;
    }
 cin >> val;
    for(int i = 1;i<m;i++){
        cin>>val;
        curr2->next = new node(val);
        curr2 = curr2->next;
    }

    curr2->next = head1->next->next->next; // make list2 join list1 at node with value 2

    Solution sol;
     node* inter = sol.intersection(head1, head2);
    
  if(inter) cout << "Intersection at node with value: " << inter->val << endl;
    else cout << "No intersection" << endl;

    return 0;
}