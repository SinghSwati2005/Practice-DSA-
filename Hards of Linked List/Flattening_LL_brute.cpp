#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct node{
    int val;
    node* next;
    node* child;
    node(int x) : val(x), next(nullptr), child(nullptr){}
};

node* convertArrToLL(vector<int>& arr){
    node* dummy = new node(-1);

    node* temp = dummy;

    for(int i =0;i<arr.size();i++){
        temp->child = new node(arr[i]);
        temp = temp->child;

    }
    return dummy->child;
}




node* flattening(node* head){
vector<int>arr;
while(head!= nullptr){
    node* t2 = head;
    while(t2!= nullptr){
        arr.push_back(t2->val);

        t2= t2->child;

    }
    head = head->next;
}

sort(arr.begin(),arr.end());
return convertArrToLL(arr);


}

node* printLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->child;
    }
    cout<<endl;
}
void printOriginalLinkedList(node* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    int n; 
    cout << "Enter number of main nodes: ";
    cin >> n;

    node* head = NULL;
    node* curr = NULL;

    // Input each main node and its child list
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter value for main node " << i+1 << ": ";
        cin >> val;

        node* newNode = new node(val);
        if (head == NULL) head = newNode;
        else curr->next = newNode;
        curr = newNode;

        int m;
        cout << "Enter number of child nodes for " << val << ": ";
        cin >> m;

        node* childCurr = curr;
        for (int j = 0; j < m; j++) {
            int childVal;
            cout << "Enter child value " << j+1 << ": ";
            cin >> childVal;

            childCurr->child = new node(childVal);
            childCurr = childCurr->child;
        }
    }

    // Flatten the list
    head = flattening(head);

    // Print flattened list
    cout << "Flattened linked list: ";
    printLL(head);

    return 0;
}
