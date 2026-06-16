#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val):data(val),left(nullptr),right(nullptr)
{}};

//build tree

node* buildtree(vector<int>&arr){
    if(arr.empty() || arr[0]==-1) return nullptr;
    int  n = arr.size();
    node* root = new node(arr[0]);
    queue<node*>q;
    q.push(root);
    int i =1;
    while(!q.empty()&&i<n){
        node* curr = q.front();
        q.pop();


        //left child 

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

void inorder(node* root , vector<int>&res){
    if(!root) return;
    inorder(root->left,res);
    res.push_back(root->data);
   inorder(root->right,res);
}

int main(){
    vector<int>arr;
    int x;
    while(cin>>x){
        arr.push_back(x);

    }
    node* root = buildtree(arr);
vector<int>res;
inorder(root,res);
 cout << "Inorder: [";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i];
        if(i < res.size() - 1) cout << ", ";
    }
    cout << "]\n";
    return 0;
}

