#include <bits/stdc++.h>
using namespace std;

// brute force
// for every index calculate the right and left max and then calculate the amount of water that can be trapped over it
// gives TLE

// T(N) => O(N * N)
// S(N) => O(1)
int trap(vector<int> &height)
{
    int ans = 0;
    int n = height.size();

    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftmax = 0;
        while (j >= 0)
        {
            leftmax = max(leftmax, height[j]);
            j--;
        }

        int rightmax = 0;
        j = i;
        while (j < n)
        {
            rightmax = max(rightmax, height[j]);
            j++;
        }

        ans += min(rightmax, leftmax) - height[i];
    }

    return ans;
}

// prefix and suffix array to compute the left and right max for each index and then compute using this formula => min(prefix[I], suffix[i])-arr[i]
// T(N) => O(N) + O(N) + O(N) => O(N)
// S(N) => O(N)

int trap(vector<int> &height)
{
    int ans = 0;
    int n = height.size();

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    left[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }

    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }

    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}

// Optimized approach using two pointer
// take 2 pointers l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively. Take two variables leftMax and rightMax and initialize them to 0. If height[l] is less than or equal to height[r] then if leftMax is less than height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the right i.e l++. If height[r] is less than height[l], then now we are dealing with the right block. If height[r] is greater than rightMax, then update rightMax to height[r] else add rightMax-height[r] to the final answer. Now move r to the left. Repeat these steps till l and r crosses each other.

// Intuition: We need a minimum of leftMax and rightMax.So if we take the case when height[l]<=height[r] we increase l++, so we can surely say that there is a block with a height more than height[l] to the right of l. And for the same reason when height[r]<=height[l] we can surely say that there is a block to the left of r which is at least of height[r]. So by traversing these cases and using two pointers approach the time complexity can be decreased without using extra space.

// T(N) => O(N)
// S(N) => O(1)

int trap(vector<int> &height)
{
    int ans = 0;
    int n = height.size();

    int leftmax = 0, rightmax = 0;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= leftmax)
            {
                leftmax = height[left];
            }
            else
            {
                ans += leftmax - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= rightmax)
            {
                rightmax = height[right];
            }
            else
            {
                ans += rightmax - height[right];
            }
            right--;
        }
    }

    return ans;
}