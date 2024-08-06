#include <bits/stdc++.h>
using namespace std;

// S(N) => O(N)
class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    // T(N) => O( log n)
    void addNum(int num)
    {
        if (maxHeap.empty() || maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        // need to check the diff between min and max heap
        // it should always be 1 else need to transfer element from one heap to another
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // T(N) => O(1)
    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else
        {
            if (minHeap.size() > maxHeap.size())
            {
                return minHeap.top();
            }
            else
            {
                return maxHeap.top();
            }
        }
    }
};

int main()
{
    return 0;
}