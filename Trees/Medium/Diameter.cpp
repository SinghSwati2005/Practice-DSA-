#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int x): data(x), left(nullptr), right(nullptr){}
};

node* buildtree(vector<int>&arr){
    if(arr.empty()|| arr[0]==-1) return nullptr;
int n = arr.size();
    node* root = new node(arr[0]);

    queue<node*>q;
    q.push(root);
int i =1;
    while(i<n  ){
node* curr = q.front();
q.pop();
  if(arr[i]!=-1){
            curr->left = new node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(arr[i]!=-1 && i<n){
            curr->right = new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int height(node* node, int &diameter ){
    if(!node)return 0;
    int lh = height(node->left,diameter);
    int rh = height(node->right,diameter);
    diameter = max(diameter,lh+rh);
    return 1+ max(lh,rh);
}
int diameter(node* root){
    int diameter =0;
    height(root,diameter);
    return diameter;
}

int main(){
    vector<int>arr;
    int x;
    while(cin>>x){
        arr.push_back(x);

    }
    node* root = buildtree(arr);


 cout<<diameter(root)<<endl;
    return 0;
}


 