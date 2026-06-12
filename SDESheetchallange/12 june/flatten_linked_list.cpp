#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node() : val(0), prev(nullptr), next(nullptr), child(nullptr) {}
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
    Node(int x, Node* next, Node* child) : val(x), prev(nullptr), next(next), child(child) {}
};

class Solution {
public:
    Node* flattenBrute(Node* head) {
        return flattenRecursive(head);
    }
    
    Node* flattenBetter(Node* head) {
        return flattenIterative(head);
    }
    
    Node* flattenOptimal(Node* head) {
        return flattenRecursive(head);
    }

private:
    Node* flattenRecursive(Node* head) {
        if (!head) return head;
        
        Node* curr = head;
        Node* tail = head;
        
        while (curr) {
            Node* nextNode = curr->next;
            
            if (curr->child) {
                Node* childTail = flattenRecursive(curr->child);
                
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
                
                curr = childTail;
            } else {
                curr = nextNode;
            }
            
            if (curr) tail = curr;
        }
        
        return head;
    }
    
    Node* flattenIterative(Node* head) {
        if (!head) return head;
        
        Node* curr = head;
        
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childTail = curr->child;
                
                while (childTail->next) {
                    childTail = childTail->next;
                }
                
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};

void printList(Node* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    Node* head = new Node(values[0]);
    Node* curr = head;
    for (size_t i = 1; i < values.size(); i++) {
        curr->next = new Node(values[i]);
        curr->next->prev = curr;
        curr = curr->next;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->child = new Node(3);
    head->next->child->next = new Node(4);
    head->next->child->next->prev = head->next->child;
    
    cout << "Original multilevel list (flattened view): ";
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        if (temp->child) {
            cout << "(child: " << temp->child->val << ") ";
        }
        temp = temp->next;
    }
    cout << endl;
    
    Solution sol;
    Node* result = sol.flattenOptimal(head);
    
    cout << "Flattened list: ";
    printList(result);
    
    return 0;
}