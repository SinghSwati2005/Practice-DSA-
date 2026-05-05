#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap based on node value
    }
};

class Solution {
public:
    ListNode* mergeSortedKList(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Push the head of each list
        for (auto list : lists) {
            if (list != NULL) pq.push(list);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* small = pq.top();
            pq.pop();

            curr->next = small;
            curr = curr->next;

            if (small->next != NULL) {
                pq.push(small->next);
            }
        }

        return dummy->next;
    }
};

int main() {
    int k;
    cin >> k; // number of lists
    vector<ListNode*> lists;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n; // length of this list
        if (n == 0) {
            lists.push_back(NULL);
            continue;
        }
        int val;
        cin >> val;
        ListNode* head = new ListNode(val);
        ListNode* curr = head;
        for (int j = 1; j < n; j++) {
            cin >> val;
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        lists.push_back(head);
    }

    Solution sol;
    ListNode* merged = sol.mergeSortedKList(lists);

    while (merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << "\n";
    return 0;
}
