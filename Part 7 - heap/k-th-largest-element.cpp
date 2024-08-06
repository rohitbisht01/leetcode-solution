#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int l;
    KthLargest(int k, vector<int> &nums)
    {
        l = k;
        for (int num : nums)
        {
            pq.push(num);
        }
    }

    int add(int val)
    {
        pq.push(val);
        while (pq.size() > l)
            pq.pop();
        return pq.top();
    }
};

int main()
{
    return 0;
}