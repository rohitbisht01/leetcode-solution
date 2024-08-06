#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heapTree, int i)
{
    int size = heapTree.size();

    // Find the largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heapTree[left] > heapTree[largest])
    {
        largest = left;
    }
    if (right < size && heapTree[right] > heapTree[largest])
    {
        largest = right;
    }

    // swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(heapTree[i], heapTree[largest]);
        heapify(heapTree, largest);
    }
}

void insert(vector<int> &heapTree, int num)
{
    int size = heapTree.size();

    if (size == 0)
    {
        heapTree.push_back(num);
    }
    else
    {
        heapTree.push_back(num);
        // heapify the whole tree
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(heapTree, i);
        }
    }
}

void deleteNode(vector<int> &heapTree, int num)
{
    int size = heapTree.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == heapTree[i])
        {
            break;
        }
    }
    swap(heapTree[i], heapTree[size - 1]);

    heapTree.pop_back(); // removes the last most element
    // and then heapify the array
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(heapTree, i);
    }
}

// Print the tree
void printArray(vector<int> &heapTree)
{
    for (int num : heapTree)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // cout << "Max Heap Implementation" << endl;
    // priority_queue<int> pq; // max heap
    // pq.push(5);
    // pq.push(1);
    // pq.push(10);
    // pq.push(30);
    // pq.push(20);

    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    // cout << endl;
    // cout << "Min Heap Implementation" << endl;
    // priority_queue<int, vector<int>, greater<int>> minpq; // min heap
    // minpq.push(5);
    // minpq.push(1);
    // minpq.push(10);
    // minpq.push(30);
    // minpq.push(20);

    // while (!minpq.empty())
    // {
    //     cout << minpq.top() << " ";
    //     minpq.pop();
    // }
    // cout << endl;

    cout << "Max Heap Implementation without built in function" << endl;
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);
    cout << "Max-Heap array: ";
    printArray(heapTree);
    deleteNode(heapTree, 4);
    cout << "After deleting an element: ";
    printArray(heapTree);

    return 0;
}