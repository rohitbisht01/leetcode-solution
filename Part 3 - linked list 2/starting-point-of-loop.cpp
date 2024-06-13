#include <bits/stdc++.h>
using namespace std;

class ListNode
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
// starting point of the loop in a ll will be the node that is encountered more than one
// iterate over the ll and check if any node is encountered more than once
// T(N) => O(N)
// S(N) => O(N)

ListNode *detectCycle(ListNode *head)
{
    unordered_map<ListNode *, int> map;
    while (head != nullptr)
    {
        if (map.count(head) != 0)
        {
            return head;
        }
        map[head] = 1;
        head = head->next;
    }

    return nullptr;
}

// optimal approach
// T(Nd) => O(N)
// S(N) => O(1)
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {

            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}