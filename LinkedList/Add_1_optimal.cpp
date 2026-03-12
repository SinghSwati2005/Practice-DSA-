#include <iostream>
using namespace std;
struct node
{
    int val;
    node *next;
    node(int x) : val(x), next(nullptr) {}
};

int helper(node *temp)
{
    if (temp == nullptr)
        return 1;
    int carry = helper(temp->next);
    temp->val = temp->val + carry;
    if (temp->val < 10)
        return 0;
    else
        temp->val = 0;

    return 1;
}

node *add1(node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        node *newnode = new node(1);

        newnode->next = head;
        return newnode;
    }
    return head;
}

node *printLL(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n, val;
    cin >> n >> val;
    node *head = new node(val);
    node *curr = head;
    for (int i = 1; i < n; i++)
    {
        cin >> val;
        curr->next = new node(val);
        curr = curr->next;
    }
    head = add1(head);
    printLL(head);
    return 0;
}