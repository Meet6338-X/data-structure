#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* getIntersectionNodeBrute(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        while (tempA) {
            ListNode* tempB = headB;
            while (tempB) {
                if (tempA == tempB) {
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        return nullptr;
    }
    
    ListNode* getIntersectionNodeBetter(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        while (tempA) {
            ListNode* tempB = headB;
            while (tempB) {
                if (tempA == tempB) {
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        return nullptr;
    }
    
    ListNode* getIntersectionNodeOptimal(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        
        return a;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

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
    vector<int> values1 = {1, 2, 3, 4, 5};
    vector<int> values2 = {6, 7, 8};
    
    ListNode* list1 = createList(values1);
    ListNode* list2 = createList(values2);
    
    list2->next->next->next = list1->next->next;
    
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    
    Solution sol;
    ListNode* intersection = sol.getIntersectionNodeOptimal(list1, list2);
    
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }
    
    return 0;
}