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
    // Brute Force: Create new list by comparing values O(n+m) time, O(n+m) space
    ListNode* mergeTwoListsBruteForce(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                tail->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Attach remaining nodes
        while (list1) {
            tail->next = new ListNode(list1->val);
            list1 = list1->next;
            tail = tail->next;
        }
        
        while (list2) {
            tail->next = new ListNode(list2->val);
            list2 = list2->next;
            tail = tail->next;
        }
        
        return dummy.next;
    }
    
    // Better: Same as brute but using dummy node technique O(n+m) time, O(1) space (excluding output)
    ListNode* mergeTwoListsBetter(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Attach remaining nodes
        tail->next = (list1) ? list1 : list2;
        
        return dummy.next;
    }
    
    // Optimal: In-place merging with recursion O(n+m) time, O(n+m) space (call stack)
    // Actually, iterative is better for space, but showing recursive approach
    ListNode* mergeTwoListsOptimal(ListNode* list1, ListNode* list2) {
        // Base cases
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1->val < list2->val) {
            list1->next = mergeTwoListsOptimal(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoListsOptimal(list1, list2->next);
            return list2;
        }
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
    vector<int> values1 = {1, 2, 4};
    vector<int> values2 = {1, 3, 4};
    
    ListNode* list1 = createList(values1);
    ListNode* list2 = createList(values2);
    
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    
    Solution sol;
    
    // Test brute force approach
    ListNode* list1Copy1 = createList(values1);
    ListNode* list2Copy1 = createList(values2);
    ListNode* merged1 = sol.mergeTwoListsBruteForce(list1Copy1, list2Copy1);
    cout << "Merged (Brute Force): ";
    printList(merged1);
    
    // Test better approach
    ListNode* list1Copy2 = createList(values1);
    ListNode* list2Copy2 = createList(values2);
    ListNode* merged2 = sol.mergeTwoListsBetter(list1Copy2, list2Copy2);
    cout << "Merged (Better): ";
    printList(merged2);
    
    // Test optimal approach
    ListNode* list1Copy3 = createList(values1);
    ListNode* list2Copy3 = createList(values2);
    ListNode* merged3 = sol.mergeTwoListsOptimal(list1Copy3, list2Copy3);
    cout << "Merged (Optimal/Recursive): ";
    printList(merged3);
    
    return 0;
}