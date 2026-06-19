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
int height(node* node, int &maxsum ){
    if(!node)return 0;
    int lh = max(0,height(node->left,maxsum));
    int rh = max(0,height(node->right,maxsum));
    maxsum = max(maxsum,lh+rh+node->data);
    return  max(lh,rh)+node->data;
}
int maxsumpath(node* root){
    int maxsum =INT_MIN;
    height(root,maxsum);
    return maxsum;
}

int main(){
    vector<int>arr;
    int x;
    while(cin>>x){
        arr.push_back(x);

    }
    node* root = buildtree(arr);


 cout<<maxsumpath(root)<<endl;
    return 0;
}


 