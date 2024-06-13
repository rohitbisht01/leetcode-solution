#include <bits/stdc++.h>
using namespace std;

// brute force => use set to store unique elements
// T(N) => O(N)
// S(N) => O(N)

int removeDuplicates(vector<int> &nums)
{
    set<int> set;
    for (int num : nums)
    {
        set.insert(num);
    }
    int i = 0;
    for (int num : set)
    {
        nums[i++] = num;
    }

    return set.size();
}

// optimized approach
// T(N) => O(N)
// S(N) => O(1)

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();

    int i = 0, j = 1;
    while (j < n)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return i + 1;
}
