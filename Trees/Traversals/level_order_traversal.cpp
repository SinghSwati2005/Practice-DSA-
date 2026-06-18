#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node* left;
    node* right;
    node(int val):data(val), left(nullptr), right(nullptr){}

};


node* buildtree(vector<int>&arr){
    if(arr.empty()|| arr[0]==-1) return nullptr;
    int n = arr.size();
    node* root = new node(arr[0]);
    queue<node*>q;
    q.push(root);
    int i= 1;

    while(!q.empty() && i<n){
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


vector<vector<int>>levelorder(node* root){
    vector<vector<int>>ans;

    if(!root)  return ans;
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i =0;i<size;i++){
            node* curr = q.front();
            q.pop();
            level.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        ans.push_back(level);

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

    vector<vector<int>>res = levelorder(root);

 cout << "Level Order Traversal:\n";
    for(auto &level : res) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
