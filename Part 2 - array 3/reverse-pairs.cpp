#include <bits/stdc++.h>
using namespace std;

// Brute force
// T(N) => O(N * N)
// S(N) => O(1)

int reversePairs(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > nums[j] * 2)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

// better approach
/*
The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just in the mergeSort() function:

In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the mergeSort().
We will add the numbers returned by the previous mergeSort() calls.
Before the merge step, we will count the number of pairs using a function, named countPairs().
We need to remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.
*/

// T(N) => O(n Log n)
// Time Complexity: O(2N*logN), where N = size of the given array.
// Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now,
// inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).
// S(N) => O(N)

void merge(vector<int> &nums, int low, int mid, int high)
{
    int left = low, right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

int countReversePairs(vector<int> &nums, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > (long long)2 * nums[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += countReversePairs(nums, low, mid, high);

    merge(nums, low, mid, high);
    return cnt;
}

int reversePairs(vector<int> &nums)
{
    // merge sort and before merging cnt the number for reverse pairs
    return mergeSort(nums, 0, nums.size() - 1);
}
