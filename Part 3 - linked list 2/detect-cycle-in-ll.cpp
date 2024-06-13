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

// brute force: using hashmap to store the node and check if we encounter the node again
// T(N) => O(N)
// S(N) => O(N)
bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    unordered_map<ListNode *, int> map;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        if (map.find(cur) != map.end())
        {
            return true;
        }
        map[cur] = 1;
        cur = cur->next;
    }
    return false;
}

// better approach
// T(N) => O(N)
// S(N) => O(1)
bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}