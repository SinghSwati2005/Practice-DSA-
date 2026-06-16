#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};

node* buildtree(vector<int>& arr) {
    if(arr.empty() || arr[0] == -1) return nullptr;
    int n = arr.size();
    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < n) {
        node* curr = q.front();
        q.pop();

        // Left child
        if(i < n && arr[i] != -1) {
            curr->left = new node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if(i < n && arr[i] != -1) {
            curr->right = new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

vector<int> postorder(node* root) {
    vector<int> post;
    if(root == nullptr) return post;

    stack<node*> s1, s2;
    s1.push(root);

    while(!s1.empty()) {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if(root->left) s1.push(root->left);
        if(root->right) s1.push(root->right);
    }

    while(!s2.empty()) {
        post.push_back(s2.top()->data);
        s2.pop();
    }
    return post;
}

int main() {
    vector<int> arr;
    int x;
    while(cin >> x) {
        arr.push_back(x);
    }

    node* root = buildtree(arr);

    vector<int> res = postorder(root);

    cout << "Postorder: [";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i];
        if(i < res.size() - 1) cout << ", ";
    }
    cout << "]\n";
    return 0;
}
