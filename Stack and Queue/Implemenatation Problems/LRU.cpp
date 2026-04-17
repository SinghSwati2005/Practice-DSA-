#include<iostream>
#include <unordered_map>
using namespace std;
class LRUCache{
public:
class Node{
    public:
    int key;
    int val;
    Node* prev ;
    Node* next;
    Node(int key , int val){
        this->key = key;
        this->val= val;

    }
};



Node* head = new Node (-1,-1);
Node* tail = new Node (-1,-1);
int cap;
unordered_map<int,Node*>m;

LRUCache(int capacity){
    cap = capacity;
    head->next = tail;
    tail->prev = head;
}

void addNode(Node* newnode){
 Node*temp = head->next;
 newnode->next = temp;
 newnode->prev = head;
 head->next =newnode;
 temp->prev = newnode;   
}
void deleteNode(Node* delnode){
Node* prevv = delnode->prev;
Node* nextt = delnode->next;
prevv->next = nextt;
nextt->prev = prevv;
}

    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};


int main() {
    int capacity;
    cout << "Enter cache capacity: ";
    cin >> capacity;
    LRUCache cache(capacity);

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    while (q--) {
        string op;
        cin >> op;
        if (op == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
            cout << "Put (" << key << "," << value << ") done\n";
        } else if (op == "get") {
            int key;
            cin >> key;
            cout << "Get(" << key << ") = " << cache.get(key) << "\n";
        }
    }
    return 0;
}