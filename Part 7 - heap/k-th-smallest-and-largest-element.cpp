#include <bits/stdc++.h>
using namespace std;

// brute force would be sorting and then returning the k-1 or n-k th element based on the question

// use priority queue
// T(N) => O(N * log N)
// S(N) => O(N)
int kthLargestElement(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : nums)
        pq.push(num);

    while (pq.size() != k)
        pq.pop();

    return pq.top();
}

// T(N) => O(N * log N)
// S(N) => O(N)
int kthSmallestElement(vector<int> &nums, int k)
{
    priority_queue<int> pq;

    for (int num : nums)
        pq.push(num);

    while (pq.size() != k)
        pq.pop();

    return pq.top();
}

// efficient approach => quicksort algorithm

int main()
{
    return 0;
}