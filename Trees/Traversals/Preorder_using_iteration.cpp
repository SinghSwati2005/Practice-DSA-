#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node* left;
    node* right;
    node(int x): data(x) ,left(nullptr),right(nullptr){}
};


node* buildtree(vector<int>&arr){
    if(arr.empty() || arr[0]==-1) return nullptr;
int n = arr.size();
node* root = new node(arr[0]);
queue<node*>q;
q.push(root);

int i =1;
while(!q.empty() && i<n){
    node* curr = q.front();
    q.pop();


    if(i<n && arr[i]!=-1){
        curr->left= new node(arr[i]);
        q.push(curr->left);
    }
    i++;
    if(i<n && arr[i]!=-1){
        curr->right= new node(arr[i]);
        q.push(curr->right);
    }
    i++;
}
return root;
}


vector<int>preorder(node*  root){
    vector<int>ans;
    if(root==nullptr) return ans;


    stack<node*>st;
    st.push(root);

    while(!st.empty()){
root = st.top();
st.pop();
ans.push_back(root->data);
if(root->right!=nullptr){
    st.push(root->right);
}
if(root->left!=nullptr){
    st.push(root->left);
}
    }
    return ans;
}

int main(){
    vector<int>arr;
    int x;
    while(cin>>x){
arr.push_back(x);
    }

    node* root = buildtree(arr);
    vector<int>res = preorder(root);
cout<<"preorder using stack";
for(int i=0; i<res.size(); i++)
{
    cout << res[i]<<" ";
}
 return 0;
}
