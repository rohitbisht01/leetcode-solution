#include <bits/stdc++.h>
using namespace std;

// brute force
// 1. Generate all the subarrays
// 2. Calculate XOR of all elements
// 3. Check xor and count

// T(N) => O(N * N)
// S(N) => O(1)W
int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xornum = 0;
        for (int j = i; j < n; j++)
        {
            xornum = xornum ^ nums[j];
            if (xornum == k)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

// better approach => using hashing
// using concept of prefix xor. Here, the prefix XOR of a subarray ending at index i, simply means the XOR of all the elements of that subarray.
/*
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array. Point to remember for unordered_map in the worst case, the searching time increases to O(N), and hence the overall time complexity increases to O(N2).

Space Complexity: O(N) as we are using a map data structure.
*/
int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    int xr = 0;
    unordered_map<int, int> map;
    map[xr]++;

    for (int i = 0; i < n; i++)
    {

        // prefix XOR till index i
        xr = xr ^ nums[i];

        // by formula: x = xr ^ k
        int x = xr ^ k;

        // add the occurrence of xr^k to count
        cnt += map[x];

        // insert the prefix xor till index i
        map[xr]++;
    }

    return cnt;
}
