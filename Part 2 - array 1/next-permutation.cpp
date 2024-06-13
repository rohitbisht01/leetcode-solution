#include <bits/stdc++.h>
using namespace std;

//  rearrange the numbers of the given array into the lexicographically next greater permutation of numbers

// approach 1: find all the permutations and store them
// search input from all the permutations and then return the next permutation
// T(N) => O(N * M!)
// S(N) => O(1) apart from recusive stack call

// approach 2: using built in function => next_permutation
// T(N) => O(N)

void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());

    for (int num : nums)
        cout << num << " ";

    cout << endl;
}

// approach 3: iterate from first index i from the back of the given array where arr[i] becomes smaller than arr[i+1], that becomes our break point or pivot element
// find the pivot element
// find the next successor to the pivot element in the right half of the array
// swap those element and reverse all the elements after the pivot element

// T(N) => O( 3 * N )
// S(N) => O(1)

void nextPermutationOptimized(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return;
}

int main()
{
    vector<int> nums = {1, 2, 3, 6, 5, 4};

    // nextPermutation(nums);
    nextPermutationOptimized(nums);

    return 0;
}