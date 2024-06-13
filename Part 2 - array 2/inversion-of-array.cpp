// Merge sort variation

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T(N) => O(N * N)
// S(N) => O(N)
int countInversion(vector<int> &nums)
{
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > nums[j])
                cnt++;
        }
    }
    return cnt;
}

// merge sort
// T(N) => O()
// S(N) => O()

int merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // storing cnt to store the count of pairs
    int cnt = 0;

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
            cnt += (mid - left + 1); // updating count
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

    return cnt; // return cnt
}

int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += merge(nums, low, mid, high);

    return cnt;
}

int numberOfInversion(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1};
    cout << countInversion(nums) << endl;

    return 0;
}