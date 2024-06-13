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
// For each k, find the last element from the list. Move it to the first.

// T(N) => O(Number of nodes present in the list*k)
// S(N) => O(1)

// better approach
// T(N) => O(length of list) + O(length of list - (length of list%k)) => O(N)
// S(N) => O(1)

// Calculate the length of the list.
// Connect the last node to the first node, converting it to a circular linked list.
// Iterate to cut the link of the last node and start a node of k%length of the list rotated list.

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 0)
        return head;

    int len = 1;
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        len++;
        temp = temp->next;
    }

    temp->next = head;
    k = k % len;
    int end = len - k;
    while (end--)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = nullptr;

    return head;
}