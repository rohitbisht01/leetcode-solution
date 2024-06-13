#include <bits/stdc++.h>
using namespace std;

// approach 1: basic sort function takes O(N log N)
// approach 2: count number of ones, twos and threes and then update the array in ascending order O( N + N )
// approach 3: dutch national flag algorithm: three pointer approach

// T(N) => O(N)
// S(N) => O(1)

void sort012(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sort012(nums);

    for (int i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}