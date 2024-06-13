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

// brute force approach
// T(N) => O(2 * N)
// S(N) => O(N)
// use stack to store all the nodes
// again traverse the ll and check if the top element if equal to the node->val
// is yes, pop the node from stack and jump to next node, and compare
// else return false

// better approach
//  reversing only half of the linked list and comparing the first and second halves. If they match, reverse the portion that was originally reversed, and then return true else return false.
// T(N) => O(N/2 + N/2 + N/2) => O(N)
// S(N) => O(1)
ListNode *reverse(ListNode *head)
{
    ListNode *cur = head, *prev = nullptr;
    while (cur != nullptr)
    {
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr)
        return true;

    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    ListNode *entry = head;
    while (slow != nullptr)
    {
        if (slow->val != entry->val)
            return false;
        slow = slow->next;
        entry = entry->next;
    }
    return true;
}