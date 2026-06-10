#include <iostream>
#include <vector>
#include <stack>
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
    ListNode *addTwoNumbersBrute(ListNode *l1, ListNode *l2)
    {
        long long num1 = 0, num2 = 0;

        while (l1)
        {
            num1 = num1 * 10 + l1->val;
            l1 = l1->next;
        }

        while (l2)
        {
            num2 = num2 * 10 + l2->val;
            l2 = l2->next;
        }

        long long sum = num1 + num2;

        if (sum == 0)
            return new ListNode(0);

        ListNode *head = nullptr;
        ListNode *curr = nullptr;

        while (sum > 0)
        {
            ListNode *newNode = new ListNode(sum % 10);
            if (!head)
            {
                head = newNode;
                curr = head;
            }
            else
            {
                curr->next = newNode;
                curr = curr->next;
            }
            sum /= 10;
        }

        return head;
    }

    ListNode *addTwoNumbersOptimal(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;

        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode *head = nullptr;

        while (!s1.empty() || !s2.empty() || carry)
        {
            int sum = carry;
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            ListNode *newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
            carry = sum / 10;
        }

        return head;
    }

    ListNode *addTwoNumbersOptimalRecursive(ListNode *l1, ListNode *l2)
    {
        return addWithCarry(l1, l2, 0);
    }

private:
    ListNode *addWithCarry(ListNode *l1, ListNode *l2, int carry)
    {
        if (!l1 && !l2 && carry == 0)
            return nullptr;

        int sum = carry;
        if (l1)
            sum += l1->val;
        if (l2)
            sum += l2->val;

        ListNode *result = new ListNode(sum % 10);

        int newCarry = (l1 && l2) ? (sum / 10) : (sum / 10);

        ListNode *next1 = l1 ? l1->next : nullptr;
        ListNode *next2 = l2 ? l2->next : nullptr;

        if (carry || (next1 || next2))
        {
            result->next = addWithCarry(next1, next2, newCarry);
        }

        return result;
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
    vector<int> values1 = {2, 4, 3};
    vector<int> values2 = {5, 6, 4};

    ListNode *l1 = createList(values1);
    ListNode *l2 = createList(values2);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution sol;

    ListNode *result1 = sol.addTwoNumbersBrute(createList(values1), createList(values2));
    cout << "Brute Force (342 + 465 = 807): ";
    printList(result1);

    ListNode *result2 = sol.addTwoNumbersOptimal(createList(values1), createList(values2));
    cout << "Optimal with Stack (342 + 465 = 807): ";
    printList(result2);

    ListNode *result3 = sol.addTwoNumbersOptimalRecursive(createList(values1), createList(values2));
    cout << "Optimal with Recursion (342 + 465 = 807): ";
    printList(result3);

    return 0;
}