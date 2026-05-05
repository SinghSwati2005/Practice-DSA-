#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeSortedKList(vector<ListNode*>& lists) {
        vector<int> storeall;
        for (auto list : lists) {
            while (list != NULL) {
                storeall.push_back(list->val);
                list = list->next;
            }
        }
        sort(storeall.begin(), storeall.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int val : storeall) {
            curr->next = new ListNode(val);
            curr = curr->next;
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

    // Print merged list
    while (merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << "\n";
    return 0;
}
