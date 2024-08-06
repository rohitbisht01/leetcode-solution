#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) =>  O(N * (sum(arr[])-max(arr[])+1))
// S(N) => O(1)

int countStudents(vector<int> &arr, int pages)
{
    int student = 1;
    int studentPages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (studentPages + arr[i] <= pages)
        {
            studentPages += arr[i];
        }
        else
        {
            student++;
            studentPages = arr[i];
        }
    }
    return student;
}

int allocatePages(vector<int> &arr, int m)
{
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if (countStudents(arr, i) == m)
            return i;
    }

    return low;
}

// using binary seach as we have a range where we can find our answer
// T(N) => O(N * log(sum(arr[])-max(arr[])+1))
// S(N) => O(1)

int allocatePagesBinary(vector<int> &arr, int m)
{
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sudents = countStudents(arr, mid);

        if (sudents == m)
            return mid;

        if (sudents < m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int m = 2;
    cout << allocatePages(arr, m) << endl;
}