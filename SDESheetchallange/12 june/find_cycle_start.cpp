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
    ListNode* detectCycleBrute(ListNode* head) {
        ListNode* temp = head;
        int pos = 0;
        while (temp) {
            ListNode* runner = head;
            int runnerPos = 0;
            while (runner) {
                if (runner == temp && pos != runnerPos) {
                    return temp;
                }
                runner = runner->next;
                runnerPos++;
            }
            temp = temp->next;
            pos++;
        }
        return nullptr;
    }
    
    ListNode* detectCycleBetter(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (!fast || !fast->next) return nullptr;
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = slow;
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
    
    ListNode* detectCycleOptimal(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (!fast || !fast->next) return nullptr;
        
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};

void printList(ListNode* head, int count) {
    int i = 0;
    while (head && i < count) {
        cout << head->val;
        if (head->next && i < count - 1) cout << " -> ";
        head = head->next;
        i++;
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
    vector<int> values = {3, 2, 0, -4};
    int pos = 1;
    
    ListNode* head = createList(values);
    
    ListNode* cycleNode = head;
    for (int i = 0; i < pos; i++) {
        cycleNode = cycleNode->next;
    }
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = cycleNode;
    
    cout << "Cycle starts at node with value: " << cycleNode->val << endl;
    
    Solution sol;
    ListNode* result = sol.detectCycleOptimal(head);
    
    if (result) {
        cout << "Detected cycle start: " << result->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
    
    return 0;
}