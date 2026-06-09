#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Brute Force: Using Stack O(n) time, O(n) space
    ListNode* reverseListBruteForce(ListNode* head) {
        if (!head || !head->next) return head;
        
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }
        
        ListNode* newHead = st.top();
        st.pop();
        curr = newHead;
        
        while (!st.empty()) {
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return newHead;
    }
    
    // Better: Using Recursion O(n) time, O(n) space (call stack)
    ListNode* reverseListBetter(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* newHead = reverseListBetter(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    
    // Optimal: Iterative In-place O(n) time, O(1) space
    ListNode* reverseListOptimal(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create list from vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Test case
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    
    cout << "Original List: ";
    printList(head);
    
    Solution sol;
    
    // Test brute force approach
    ListNode* headCopy1 = createList(values);
    ListNode* reversed1 = sol.reverseListBruteForce(headCopy1);
    cout << "Reversed (Brute Force): ";
    printList(reversed1);
    
    // Test better approach
    ListNode* headCopy2 = createList(values);
    ListNode* reversed2 = sol.reverseListBetter(headCopy2);
    cout << "Reversed (Better/Recursive): ";
    printList(reversed2);
    
    // Test optimal approach
    ListNode* headCopy3 = createList(values);
    ListNode* reversed3 = sol.reverseListOptimal(headCopy3);
    cout << "Reversed (Optimal/Iterative): ";
    printList(reversed3);
    
    return 0;
}