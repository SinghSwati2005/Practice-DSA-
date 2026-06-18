#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int x): data(x), left(nullptr), right(nullptr) {}
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

        if(i < n && arr[i] != -1) {
            curr->left = new node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

vector<int> inorder(node* root) {
    vector<int> ans;
    stack<node*> st;
    node* curr = root;

    while(curr != nullptr || !st.empty()) {
        // Go left as far as possible
        while(curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        // Process node
        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        // Go right
        curr = curr->right;
    }
    return ans;
}

int main() {
    vector<int> arr;
    int x;
    while(cin >> x) {
        arr.push_back(x);
    }

    node* root = buildtree(arr);
    vector<int> res = inorder(root);

    cout << "Inorder using stack: [";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i];
        if(i < res.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
