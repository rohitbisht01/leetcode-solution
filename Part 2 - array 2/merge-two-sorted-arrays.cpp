#include <bits/stdc++.h>
using namespace std;

// T(N) => O( M + N )
// S(N) => O( N + M )
void merge(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    int n = nums1.size();
    int m = nums2.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            ans.push_back(nums1[i++]);
        }
        else
        {
            ans.push_back(nums2[j++]);
        }
    }

    while (i < n)
    {
        ans.push_back(nums1[i++]);
    }
    while (j < m)
    {
        ans.push_back(nums2[j++]);
    }

    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
}

// T(N) => O(min(N,M)) + O(N * log N) + O( M * log M)
// S(N) => O(1)

// We can think of Iterating in arr1 and whenever we encounter an element that is greater than the first element of arr2, just swap it. Now rearrange the arr2 in a sorted manner, after completion of the loop we will get elements of both the arrays in non-decreasing order.

void mergeSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    int left = n - 1, right = 0;
    while (left >= 0 && right < m)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for (int num : nums1)
        cout << num << " ";
    for (int num : nums2)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, nums2);

    mergeSortedArrays(nums1, nums2);

    return 0;
}