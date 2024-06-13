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

// brute force : use set to store one ll and then traverse the second ll and check if node is present in the set or not
// T(N) => O(N + M)
// S(N) => O(N)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    set<ListNode *> set;
    while (headA != nullptr)
    {
        set.insert(headA);
        headA = headA->next;
    }

    while (headB != nullptr)
    {
        if (set.find(headB) != set.end())
        {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
}

// better approach: difference in lengths
// T(N) => O(N + M)
// S(N) => O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    int n = 0, m = 0;

    ListNode *l1 = headA, *l2 = headB;
    while (l1 != nullptr)
    {
        n++;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        m++;
        l2 = l2->next;
    }

    int diff = n - m;
    if (diff < 0)
    {
        while (diff++ != 0)
        {
            headB = headB->next;
        }
    }
    else
    {
        while (diff-- != 0)
        {
            headA = headA->next;
        }
    }

    while (headA != nullptr && headB != nullptr)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}