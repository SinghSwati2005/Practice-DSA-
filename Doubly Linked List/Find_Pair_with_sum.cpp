// Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.



// Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.


// Example 1

// Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7

// Output: [[1, 6], [2, 5]]

// Explanation:

// 1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.

// Example 2

// Input: head = [1, 5, 6], target = 6

// Output: [[1, 5]]

// Explanation:

// 1 + 5 = 6 is the only valid pair.

#include<iostream>
#include<vector>
using namespace std;

struct node{
int val;
node* next ; node* prev;
node (int x) : val(x) , next(nullptr), prev(nullptr){}
};

node* findtail (node* head){
    node* tail = head;
    while(tail->next != NULL) tail = tail->next;
    return tail;
}
vector<pair<int,int>> findPairs(node* head, int k){

    vector<pair<int,int>>ans;

node* left = head;
node* right = findtail(head);

while(left->val<right->val){
    if(left->val + right->val == k){
        ans.push_back({left->val,right->val});
        left = left->next;
        right = right->prev;
    }
    else if(left->val+right->val>k){
        right = right->prev;
    }
    else{
        left = left->next;
    }
}
return ans;
}
int main(){
    int n ,k;
    cin>>n>>k;
    int val;
    cin>>val;
    node* head = new node(val);
    node* curr = head;
    for(int i =1;i<n;i++){
        cin>>val;
        node* newnode = new node(val);
        curr->next = newnode;
        newnode->prev = curr;
        curr = newnode;
    }

  vector<pair<int,int>> result = findPairs(head, k);
    for (auto &p : result) {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
  return 0;
}