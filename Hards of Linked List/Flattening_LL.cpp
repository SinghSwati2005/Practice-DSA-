#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node* child;
    node(int x) : val(x), next(nullptr), child(nullptr) {}
};

// Merge two sorted linked lists using child pointers
node* merge(node* l1, node* l2) {
    node* dummy = new node(-1);
    node* res = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            res->child = l1;
            res = l1;
            l1 = l1->child;
        } else {
            res->child = l2;
            res = l2;
            l2 = l2->child;
        }
        res->next = nullptr; // ensure next is null
    }

    if (l1) res->child = l1;
    else res->child = l2;

    return dummy->child;
}

// Recursive function to flatten the list
node* flattening(node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Flatten the rest of the list
    head->next = flattening(head->next);

    // Merge current list with flattened next list
    head = merge(head, head->next);

    return head;
}

// Print flattened list using child pointers
void printLL(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->child;
    }
    cout << endl;
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
