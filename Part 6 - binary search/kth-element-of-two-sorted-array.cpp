#include <bits/stdc++.h>
using namespace std;

// brute force
// store all the elements from arr1 and aarr2 and sort the arr3 and return k-1 th element

// T(N) => O(N+M log (M+N))
// S(N) => O(M + N)
int kthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    vector<int> arr3;
    for (int num : arr1)
        arr3.push_back(num);
    for (int num : arr2)
        arr3.push_back(num);
    sort(arr3.begin(), arr3.end());

    return arr3[k - 1];
}

// useing merge sort reducing time complexity a bit
// or while applying merge sort, maintain a cnt variable to store the number of elements has been processed when cnt becomes equal to k return element at that point, reducing S(N) => O(1)
// T(N) => O(N + M)
// S(N) => O(1)

int kthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    // code here
    int i = 0, j = 0;
    int n1 = arr1.size(), n2 = arr2.size();
    int cnt = 0;
    while (i < n1 && j < n2)
    {
        // cout << cnt << arr1[i] << arr2[j] << endl;
        if (arr1[i] < arr2[j])
        {
            if (cnt == k - 1)
                return arr1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == k - 1)
                return arr2[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == k - 1)
            return arr1[i];
        i++;
    }
    while (j < n2)
    {
        if (cnt == k - 1)
            return arr2[j];
        j++;
    }
    return -1;
}

// efficient approach is using binary search

int main()
{
    return 0;
}