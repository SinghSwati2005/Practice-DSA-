#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int x): data(x), left(nullptr),right(nullptr){}
};

node* buildtree(vector<int>&arr){
     if(arr.empty()|| arr[0]==-1) return nullptr;
     int n = arr.size();
     node* root = new node(arr[0]);
     queue<node*>q;
     q.push(root);
     int i=1;
     while(i<n && arr[i]!=-1){
        node* curr = q.front();
        q.pop();

        if(arr[i]!=-1 &&i<n){
         curr->left = new node(arr[i]);
         q.push(curr->left);
        }
        i++;
        if(arr[i]!=-1 &&i<n){
         curr->right = new node(arr[i]);
         q.push(curr->right);
        }
        i++;


     }
     return root;
}


int check(node* root){
    if(root==NULL) return false;
    int lh = check(root->left);
    if(lh==-1) return -1;
    int rh = check(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}

bool balance_tree(node* root){
    return check(root)!=-1;
}

int main(){
    vector<int>arr;
    int x;
    while(cin>>x){
        arr.push_back(x);
    }

    node* root = buildtree(arr);
   int res = balance_tree(root);

    
  cout<<((res)?"true":"false");

    return 0;
}


