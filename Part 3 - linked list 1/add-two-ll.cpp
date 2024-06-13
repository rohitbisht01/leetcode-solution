#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

// T(N) => O(N + M)
// S(N) = > O(N + M)
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    while (l1 != nullptr || l2 != nullptr || carry)
    {
        int sum = 0;
        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        temp->next = new ListNode(sum % 10);
        carry = sum / 10;

        temp = temp->next;
    }
    return dummy->next;
}