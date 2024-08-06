#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force
// traverse k linked list and store all the nodes in an array sort the array and then create a linked list for the array elements
// T(N) => (N * K * log(N * K))
// S(N) => O(N * K)

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    vector<int> arr;
    for (ListNode *ls : lists)
    {
        ListNode *cur = ls;
        while (cur != nullptr)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }
    }

    sort(arr.begin(), arr.end());
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    for (int num : arr)
    {
        temp->next = new ListNode(num);
        temp = temp->next;
    }

    return dummy->next;
}

// using min heap
// T(N) => O(N * K log(K))
// S(N) => O(N * K)

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;
        int k = lists.size();

        if (k == 0)
            return nullptr;

        // push all the start element of k linked lists
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != nullptr)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode *head = nullptr, *tail = nullptr;
        while (minHeap.size() > 0)
        {
            ListNode *top = minHeap.top();
            minHeap.pop();

            if (top->next != nullptr)
            {
                minHeap.push(top->next);
            }

            if (head == nullptr)
            {
                // answer list is empty
                head = top;
                tail = top;
            }
            else
            {
                // insert at ll
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}