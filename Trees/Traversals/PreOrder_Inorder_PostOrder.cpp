#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Build tree from level order input with -1 as null
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();
        // Left child
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Preorder, Inorder, Postorder in one traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;
    if (!root) return {};
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);
            if (it.first->left) st.push({it.first->left, 1});
        } else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it);
            if (it.first->right) st.push({it.first->right, 1});
        } else {
            post.push_back(it.first->data);
        }
    }
    return {pre, in, post};
}

int main() {
    // Read input
    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
    }

    // Build tree
    Node* root = buildTree(arr);

    // Get traversals
    auto traversals = preInPostTraversal(root);

    // Print Preorder
    cout << "Preorder: [";
    for (int i = 0; i < traversals[0].size(); i++) {
        cout << traversals[0][i];
        if (i < traversals[0].size() - 1) cout << ", ";
    }
    cout << "]\n";

    // Print Inorder
    cout << "Inorder: [";
    for (int i = 0; i < traversals[1].size(); i++) {
        cout << traversals[1][i];
        if (i < traversals[1].size() - 1) cout << ", ";
    }
    cout << "]\n";

    // Print Postorder
    cout << "Postorder: [";
    for (int i = 0; i < traversals[2].size(); i++) {
        cout << traversals[2][i];
        if (i < traversals[2].size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
