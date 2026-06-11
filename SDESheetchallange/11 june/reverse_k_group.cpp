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
    ListNode* reverseKGroupBrute(ListNode* head, int k) {
        return reverseKGroupRecursive(head, k);
    }
    
    ListNode* reverseKGroupBetter(ListNode* head, int k) {
        return reverseKGroupRecursive(head, k);
    }
    
    ListNode* reverseKGroupOptimal(ListNode* head, int k) {
        return reverseKGroupRecursive(head, k);
    }

private:
    ListNode* reverseKGroupRecursive(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        
        if (count < k) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        if (curr) {
            head->next = reverseKGroupRecursive(curr, k);
        }
        
        return prev;
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
    vector<int> values = {1, 2, 3, 4, 5};
    int k = 2;
    
    ListNode* head = createList(values);
    
    cout << "Original List: ";
    printList(head);
    
    Solution sol;
    ListNode* result = sol.reverseKGroupOptimal(head, k);
    
    cout << "Reversed in groups of " << k << ": ";
    printList(result);
    
    return 0;
}