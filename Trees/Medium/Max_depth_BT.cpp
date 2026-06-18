#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int x): data(x),left(nullptr),right(nullptr){}
};

node* buildtree(vector<int>&arr){
    if(arr.empty()|| arr[0]==-1) return nullptr;
int n = arr.size();
    node* root = new node(arr[0]);

    queue<node*>q;
    q.push(root);

    int i=1;
    while(!q.empty()&& i<n){
       node* curr = q.front();
       q.pop();

       if(i<n && arr[i]!=-1){
        curr->left = new node(arr[i]);
        q.push(curr->left);
       }
       i++;
       if(i<n && arr[i]!=-1){
        curr->right = new node(arr[i]);
        q.push(curr->right);
       }
       i++;
    }
return root;

}

int maxdepth(node* root){
    queue<node*>q;
    if(root==nullptr) return 0;
  
    q.push(root);
      int levl =0;
while(!q.empty()){
    int size = q.size();
    levl++;
    for(int i=0;i<size;i++){
        node* curr = q.front();
        q.pop();
        if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right) ;
    }

}
return levl;
}

int main(){
    vector<int>arr;
    int x;
    while(cin>>x){
        arr.push_back(x);
    }

    node* root = buildtree(arr);
   int res = maxdepth(root);

    
   cout<<res<<" ";

    return 0;
}

