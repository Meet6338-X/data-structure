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
    bool isPalindromeBrute(ListNode* head) {
        if (!head || !head->next) return true;
        
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        
        int mid = count / 2;
        int* arr = new int[count];
        
        temp = head;
        for (int i = 0; i < count; i++) {
            arr[i] = temp->val;
            temp = temp->next;
        }
        
        for (int i = 0; i < mid; i++) {
            if (arr[i] != arr[count - 1 - i]) {
                delete[] arr;
                return false;
            }
        }
        delete[] arr;
        return true;
    }
    
    bool isPalindromeBetter(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalf = slow->next;
        ListNode* prev = nullptr;
        ListNode* curr = secondHalf;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        secondHalf = prev;
        
        ListNode* first = head;
        ListNode* second = secondHalf;
        bool result = true;
        while (second) {
            if (first->val != second->val) {
                result = false;
                break;
            }
            first = first->next;
            second = second->next;
        }
        
        curr = secondHalf;
        prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return result;
    }
    
    bool isPalindromeOptimal(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = prev;
        
        curr = head;
        ListNode* second = slow->next;
        while (second) {
            if (curr->val != second->val) {
                return false;
            }
            curr = curr->next;
            second = second->next;
        }
        return true;
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
    vector<int> values = {1, 2, 2, 1};
    ListNode* head = createList(values);
    
    cout << "List: ";
    printList(head);
    
    Solution sol;
    cout << "Is Palindrome (Optimal): " << (sol.isPalindromeOptimal(head) ? "true" : "false") << endl;
    
    return 0;
}