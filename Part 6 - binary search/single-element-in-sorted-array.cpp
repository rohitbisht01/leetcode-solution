#include <bits/stdc++.h>
using namespace std;

// approaches
// 1. using two for loop and check if an element is encountered only one once
// 2. use frequency array
// 3. xor operation
// 5. simple brute force => check edge cases and check for adjacent elements to be not equal
// 4. if the array is sorted use binary search => go with odd even index

// brute force
// T(N) => O(N)
// S(N) => O(1)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    for (int i = 1; i < n - 2; i++)
    {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            return nums[i];
    }

    return -1;
}

// T(N) => O(log N)
// S(N) => O(1)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];

        // having even odd pair
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
            (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    return 0;
}