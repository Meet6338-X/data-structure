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
    bool hasCycleBrute(ListNode* head) {
        ListNode* temp = head;
        while (temp) {
            ListNode* runner = head;
            while (runner != temp) {
                if (runner == temp->next) {
                    return true;
                }
                runner = runner->next;
            }
            temp = temp->next;
        }
        return false;
    }
    
    bool hasCycleBetter(ListNode* head) {
        ListNode* temp = head;
        int pos = 0;
        while (temp) {
            ListNode* runner = head;
            int runnerPos = 0;
            while (runner) {
                if (runner == temp && pos != runnerPos) {
                    return true;
                }
                runner = runner->next;
                runnerPos++;
            }
            temp = temp->next;
            pos++;
        }
        return false;
    }
    
    bool hasCycleOptimal(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

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
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    
    Solution sol;
    
    head->next->next->next->next = head->next;
    
    cout << "Has cycle (Optimal/Floyd's Cycle Detection): " << (sol.hasCycleOptimal(head) ? "true" : "false") << endl;
    
    return 0;
}