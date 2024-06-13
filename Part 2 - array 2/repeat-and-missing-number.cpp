#include <bits/stdc++.h>
using namespace std;

// frequency array or hashing
// T(N) => O(N + N)
// S(N) => O(N)
vector<int> findRepeatAndMissing(vector<int> &nums)
{
    int n = nums.size();
    int freq[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }

    int repeating = -1, missing = -1;
    for (int i = 1; i < n + 1; i++)
    {
        if (freq[i] == 0)
            missing = i;
        else if (freq[i] == 2)
            repeating = i;
    }
    return {repeating, missing};
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};
    vector<int> ans = findRepeatAndMissing(nums);
    for (int num : ans)
        cout << num << " ";
    cout << endl;

    return 0;
}