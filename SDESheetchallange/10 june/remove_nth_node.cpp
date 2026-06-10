#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEndBrute(ListNode *head, int n)
    {
        int count = 0;
        ListNode *curr = head;
        while (curr)
        {
            count++;
            curr = curr->next;
        }

        int pos = count - n;

        if (pos == 0)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        curr = head;
        for (int i = 0; i < pos - 1; i++)
        {
            curr = curr->next;
        }

        ListNode *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }

    ListNode *removeNthFromEndOptimal(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *slow = dummy;
        ListNode *fast = dummy;

        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy->next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *curr = head;
    for (size_t i = 1; i < values.size(); i++)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    int n = 2;

    cout << "Original List: ";
    ListNode *head1 = createList(values);
    printList(head1);

    Solution sol;

    ListNode *headCopy1 = createList(values);
    ListNode *result1 = sol.removeNthFromEndBrute(headCopy1, n);
    cout << "Brute Force (remove " << n << " from end): ";
    printList(result1);

    ListNode *headCopy2 = createList(values);
    ListNode *result2 = sol.removeNthFromEndOptimal(headCopy2, n);
    cout << "Optimal (remove " << n << " from end): ";
    printList(result2);

    return 0;
}