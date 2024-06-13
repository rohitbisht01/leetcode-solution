#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

// brute force:
// store all the nodes of ll in an array
// sort them in ascending order
// create a linked list using the array
// T(N) => O(N log N)
// S(N) => O(N)

Node *flatten(Node *root)
{
    // Your code here
    vector<int> vec;
    while (root != nullptr)
    {
        Node *cur = root;
        while (cur != nullptr)
        {
            vec.push_back(cur->data);
            cur = cur->bottom;
        }
        root = root->next;
    }
    sort(vec.begin(), vec.end());
    Node *head = new Node(-1);
    Node *temp = head;
    for (int i = 0; i < vec.size(); i++)
    {
        temp->bottom = new Node(vec[i]);
        temp = temp->bottom;
    }
    return head->bottom;
}

Node *merge(Node *headA, Node *headB)
{
    if (headA == nullptr)
        return headB;
    if (headB == nullptr)
        return headA;

    Node *dummy = new Node(-2);
    Node *temp = dummy;
    while (headA != nullptr && headB != nullptr)
    {
        if (headA->data < headB->data)
        {
            temp->bottom = headA;
            headA = headA->bottom;
        }
        else
        {
            temp->bottom = headB;
            headB = headB->bottom;
        }
        temp = temp->bottom;
    }
    if (headA != nullptr)
        temp->bottom = headA;
    if (headB != nullptr)
        temp->bottom = headB;

    return dummy->bottom;
}

// better approach

// Instead of collecting all node values into an array and then sorting them, we can merge these pre-sorted lists directly during the traversal, eliminating the need for additional sorting steps. This merge operation can be performed efficiently in place without allocating extra space for the combined linked list.

// Time Complexity: O( N*(2M) ) ~ O(2 N*M)where N is the length of the linked list along the next pointer and M is the length of the linked list along the child pointers.

// The merge operation in each recursive call takes time complexity proportional to the length of the linked lists being merged as they have to iterate over the entire lists. Since the vertical depth of the linked lists is assume to be M, the time complexity for a single merge operation is proportional to O(2*M).
// This operation operation is performed N number of times (to each and every node along the next pointer list) hence the resultant time complexity becomes: O(N* 2M).
// Space Complexity : O(1) as this algorithm uses no external space or additional data structures to store values. But a recursive stack uses O(N) space to build the recursive calls for each node along the next pointer list.
Node *flatten(Node *root)
{
    // Your code here
    if (root == nullptr || root->next == nullptr)
        return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}
