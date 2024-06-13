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

//  we can find the middle node of a linked list by traversing the linked list and finding the total number of nodes as `count`. Then we reset the traversal pointer and traverse to the node at the [count/2 + 1]th position. That will be the middle node.

// T(N) => O(N + N)
// S(N) => O(1)
ListNode *middleNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int count = 0;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        count++;
        cur = cur->next;
    }

    int mid = count / 2 + 1;
    cur = head;

    while (cur != nullptr)
    {
        mid = mid - 1;

        if (mid == 0)
        {
            break;
        }

        cur = cur->next;
    }
    return cur;
}

// slow and fast pointer approach
// T(N) => O( N / 2 )
// S(N) => O(1)
ListNode *middleNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {}