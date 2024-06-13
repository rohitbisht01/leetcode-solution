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
// store all the nodes in list and sort them and then create a new updated linked list of the sorted list
// T(N) =>  O(N1 + N2) + O(N log N) + O(N) where N1 is the number of linked list nodes in the first list and N2 is the number of linked list nodes in the second list and N is the total number of nodes (N1+N2). Traversing both lists into the array owes O(N1 + N2), sorting the array takes O((N1+N2)*log(N1+N2)) and then traversing the sorted array and creating a list gives us another O(N1+N2).
// Space Complexity : O(N)+O(N) where N is the total number of nodes from both lists, N1 + N2. O(N) to store all the nodes of both the lists in an external array and another O(N) to create a new combined list.

// better approach: using merge sort
// Time Complexity: O(N1+N2) where N1 is the number of nodes in the first linked list and N1 in the second linked list as we traverse both linked lists in a single pass for merging without any additional loops or nested iterations.
// Space Complexity : O(1) as no additional data structures or space is allocated for storing data, only a constant space for pointers to maintain for traversing the linked list.
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    if (list2 != nullptr)
    {
        temp->next = list2;
    }

    return dummy->next;
}