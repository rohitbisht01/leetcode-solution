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

// T(N) => O(1)
// S(N) => O(1)
void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int main() {}