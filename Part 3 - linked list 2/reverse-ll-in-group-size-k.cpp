struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// approach
// reverse the ll and also maintain cnt varible to know how many nodes have been traversed
// and then recursively traverse the remaining nodes
// T(N) => O(N)
// S(N) => O(1)

struct node *reverseIt(struct node *head, int k)
{
    // Complete this method
    int cnt = 0;
    node *cur = head, *prev = nullptr, *temp = nullptr;
    while (cur != nullptr && cnt < k)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        cnt++;
    }

    if (temp != nullptr)
    {
        head->next = reverseIt(temp, k);
    }

    return prev;
}