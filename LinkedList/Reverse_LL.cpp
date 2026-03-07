#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;  // number of nodes
    if (n <= 0) return 0;

    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }

    ListNode* reversedHead = reverseList(head);

    // print reversed list
    ListNode* temp = reversedHead;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}
