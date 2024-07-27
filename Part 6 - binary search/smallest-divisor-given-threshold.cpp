#include <bits/stdc++.h>
using namespace std;

// brute force
// find max and start from 1

// T(N) => O(N * N)
// S(N) => O(1)

int divisorSum(vector<int> &nums, int num)
{
    int cnt = 0;
    for (int ele : nums)
    {
        int div = ceil((double)ele / (double)num);
        cnt += div;
    }
    return cnt;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int maxi = INT_MIN;
    for (int num : nums)
    {
        maxi = max(maxi, num);
    }
    int n = nums.size();
    int minDivisor = INT_MAX;
    for (int i = 1; i <= maxi; i++)
    {
        int sum = divisorSum(nums, i);
        if (sum <= threshold)
        {
            return i;
        }
    }
    return -1;
}

// using binary search
// Now, we are not given any sorted array on which we can apply binary search. Upon closer observation, we can recognize that our answer space, represented as [1, max(arr[])], is actually sorted.

// T(N) => O(N log M)
// S(N) => O(1)

int divisorSum(vector<int> &nums, int num)
{
    int cnt = 0;
    for (int ele : nums)
    {
        int div = ceil((double)ele / (double)num);
        cnt += div;
    }
    return cnt;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n > threshold)
        return -1;

    int maxi = INT_MIN;
    for (int num : nums)
    {
        maxi = max(maxi, num);
    }

    int low = 1, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (divisorSum(nums, mid) <= threshold)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{

    return 0;
}