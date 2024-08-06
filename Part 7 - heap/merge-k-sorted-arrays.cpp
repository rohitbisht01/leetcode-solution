#include <bits/stdc++.h>
using namespace std;

// brute force
// store all elements in an array and sort it
// T(N) => O(N * K * log (N*K)), Since the resulting array is of size N*K.
// S(N) => O(N * K), The output array is of size N * K.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> ans;
    for (vector<int> temp : arr)
    {
        for (int num : temp)
            ans.push_back(num);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// using min heap
// T(N) => O(N * K * log(K))
// S(N) => O(N * K)

// general idea: use a min heap with k elements to track the smallest number from all arrays. continue removing the smallest element from heap until all numbers are added to the result array

class node
{
public:
    int data, arrInd, eleInd;
    node(int data, int arrInd, int eleInd)
    {
        this->data = data;
        this->arrInd = arrInd;
        this->eleInd = eleInd;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node *, vector<node *>, compare> minHeap;

        // Insert first element of each sorted array into the heap
        for (int i = 0; i < K; i++)
        {
            node *temp = new node(arr[i][0], i, 0);
            minHeap.push(temp);
        }

        vector<int> ans;

        // Extract the minimum element and insert the next element from the same array into the heap
        while (!minHeap.empty())
        {
            node *temp = minHeap.top();
            ans.push_back(temp->data);
            minHeap.pop();

            // Insert the next element from the same array
            int arrInd = temp->arrInd;
            int eleInd = temp->eleInd;

            if (eleInd + 1 < arr[arrInd].size())
            {
                node *newEle = new node(arr[arrInd][eleInd + 1], arrInd, eleInd + 1);
                minHeap.push(newEle);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}