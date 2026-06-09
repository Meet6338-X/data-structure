#include <iostream>
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
    ListNode* middleNodeBruteForce(ListNode* head) {
        if (!head) return nullptr;
        
        // First pass: count nodes
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        // Second pass: traverse to middle
        int middle = count / 2;
        curr = head;
        for (int i = 0; i < middle; i++) {
            curr = curr->next;
        }
        return curr;
    }
    
    ListNode* middleNodeBetter(ListNode* head) {
        if (!head) return nullptr;
        
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        return nodes[nodes.size() / 2];
    }
    
    ListNode* middleNodeOptimal(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move fast by 2 and slow by 1
        // When fast reaches end, slow will be at middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    // Test case 1: Odd length
    vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(values1);
    
    cout << "List 1: ";
    printList(head1);
    
    Solution sol;
    
    // Test brute force approach
    ListNode* headCopy1_1 = createList(values1);
    ListNode* middle1_1 = sol.middleNodeBruteForce(headCopy1_1);
    cout << "Middle (Brute Force): " << middle1_1->val << endl;
    
    // Test better approach
    ListNode* headCopy1_2 = createList(values1);
    ListNode* middle1_2 = sol.middleNodeBetter(headCopy1_2);
    cout << "Middle (Better/Array): " << middle1_2->val << endl;
    
    // Test optimal approach
    ListNode* headCopy1_3 = createList(values1);
    ListNode* middle1_3 = sol.middleNodeOptimal(headCopy1_3);
    cout << "Middle (Optimal/Tortoise-Hare): " << middle1_3->val << endl;
    
    cout << endl;
    
    // Test case 2: Even length
    vector<int> values2 = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createList(values2);
    
    cout << "List 2: ";
    printList(head2);
    
    // Test brute force approach
    ListNode* headCopy2_1 = createList(values2);
    ListNode* middle2_1 = sol.middleNodeBruteForce(headCopy2_1);
    cout << "Middle (Brute Force): " << middle2_1->val << endl;
    
    // Test better approach
    ListNode* headCopy2_2 = createList(values2);
    ListNode* middle2_2 = sol.middleNodeBetter(headCopy2_2);
    cout << "Middle (Better/Array): " << middle2_2->val << endl;
    
    // Test optimal approach
    ListNode* headCopy2_3 = createList(values2);
    ListNode* middle2_3 = sol.middleNodeOptimal(headCopy2_3);
    cout << "Middle (Optimal/Tortoise-Hare): " << middle2_3->val << endl;
    
    return 0;
}