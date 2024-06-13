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

// brute force
// delete the (L-N+1)th node from the start of the linked list,
// calculate the length of the ll
// now delete the len-n+1 th node

// edge case
// 1. delete the (L-N+1)th node from the start of the linked list,
// 2. If N equals the length of the linked list, we have to delete the head of the linked list.

// better approach
// To enhance efficiency, we will involve two pointers, a fast pointer and a slow pointer. The fast-moving pointer will initially be exactly N nodes ahead of the slow-moving pointer. After which, both of them will move one step at a time. When the fast pointer reaches the last node, i.e., the L-th node, the slow is guaranteed to be at the (L-N)-th node, where L is the total length of the linked list.
// T(N) => O(N)
// S(N) => O(1)

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
        return head;

    ListNode *slow = head, *fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == nullptr)
    {
        return head->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
}