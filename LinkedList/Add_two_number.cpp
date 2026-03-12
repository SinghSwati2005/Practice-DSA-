#include<iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
};

node* add2(node* l1, node* l2) {
    node* dummy = new node(0);  // dummy node with 0
    node* temp = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry) {
        int sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;

        temp->next = new node(sum % 10);
        temp = temp->next;
    }
    return dummy->next;
}

void printLL(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, m, val;
    cin >> n;
    node* head1 = nullptr;
    node* curr1 = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> val;
        if (!head1) {
            head1 = new node(val);
            curr1 = head1;
        } else {
            curr1->next = new node(val);
            curr1 = curr1->next;
        }
    }

    cin >> m;
    node* head2 = nullptr;
    node* curr2 = nullptr;

    for (int i = 0; i < m; i++) {
        cin >> val;
        if (!head2) {
            head2 = new node(val);
            curr2 = head2;
        } else {
            curr2->next = new node(val);
            curr2 = curr2->next;
        }
    }

    node* result = add2(head1, head2);
    printLL(result);

    return 0;
}
