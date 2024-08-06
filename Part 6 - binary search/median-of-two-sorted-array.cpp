#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N log N)
// S(N) => O(N + M)

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    for (int num : nums1)
        ans.push_back(num);
    for (int num : nums2)
        ans.push_back(num);

    sort(ans.begin(), ans.end());
    int n = ans.size();
    double temp = 1.0;
    if (n % 2 == 1)
        temp = (double)ans[n / 2.0];
    else
        temp = (ans[n / 2] + ans[(n - 1) / 2]) / 2.0;

    return temp;
}

// instead of sort function we can implement merge sort which reduces our time complexity to O(M + N) and space complexity to O(M + N)

// To optimize the space used in the previous approach, we can eliminate the third array used to store the final merged result.After closer examination, we realize that we only need the two middle elements at indices(n1 + n2) / 2 and ((n1 + n2) / 2) - 1, rather than the entire merged array, to solve the problem effectively.
// we only need to keep track of middle two elements

// T(N) => O(N + M)
// S(N) => O(1)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2; // total size
    // required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == ind1)
                ind1el = nums1[i];
            if (cnt == ind2)
                ind2el = nums1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = nums2[j];
            if (cnt == ind2)
                ind2el = nums2[j];
            cnt++;
            j++;
        }
    }

    // copy the left-out elements:
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = nums1[i];
        if (cnt == ind2)
            ind2el = nums1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = nums2[j];
        if (cnt == ind2)
            ind2el = nums2[j];
        cnt++;
        j++;
    }

    // Find the median:
    if (n % 2 == 1)
    {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

// another approach which is more optimized => using binary search

int main()
{
    return 0;
}