#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int data)
    {
        val = data;
        next = nullptr;
        random = nullptr;
    }
    Node(int data, Node *next, Node *random)
    {
        val = data;
        next = next;
        random = random;
    }
};

// brute force approach
// To create a deep copy of the original linked list we can use a map to establish a relationship between original nodes and their copied nodes.
// We traverse the list first to create a copied node for each original node then traverse and establish the correct connections between the copied nodes similar to the arrangement of next and random pointers of the original pointers. In the end, return the head of the copied list obtained from the map.

// Step 1: Create copies of each node and store them in the map
// Step 2: Connect the next and random pointers of the copied nodes using the map
// Return the head of the deep copied list from the map

// Time Complexity: O(2N) where N is the number of nodes in the linked list. The linked list is traversed twice, once for creating copies of each node and for the second time to set the next and random pointers for each copied node. The time to access the nodes in the map is O(1) due to hashing.

// Space Complexity : O(N)+O(N)where N is the number of nodes in the linked list as all nodes are stored in the map to maintain mappings and the copied linked lists takes O(N) space as well.

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return head;

    Node *temp = head;

    // create unordered_map to map original nodes to their corresponding copied nodes
    unordered_map<Node *, Node *> map;

    // create copies of each node and store them in the map
    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->val);
        // map the original node to its corresponding copied node in the map
        map[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    // connect the next and the random poiinters of the copied nodes using map
    while (temp != nullptr)
    {
        Node *copyNode = map[temp];
        copyNode->random = map[temp->random];
        copyNode->next = map[temp->next];
        temp = temp->next;
    }

    return map[head];
}

// better approach

// Steps
// Traverse the original node and create a copy of each node and insert it in between the original node and the next node.
// Traverse this modified list and for each original node that has a random pointer, set the copied node’s random pointer to the corresponding copies random node. If the original node’s random pointer is full, set the copied node’s random pointe to null as well.
//  RecursionTraverse the modified list again and extract the coped nodes by breaking the links between the original nodes and the copied nodes. Revert the original list to its initial state by fixing the next pointers.

// T(N) => O(3 * N) =>  The algorithm makes three traversals of the linked list, once to create copies and insert them between original nodes, then to set the random pointers of the copied nodes to their appropriate copied nodes and then to separate the copied and original nodes.
// S(N) => O(N)

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return head;

    // create copy nodes and attach them in between
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *next = temp->next;
        Node *random = temp->random;
        temp->next = new Node(temp->val, next, random);
        temp = temp->next->next;
    }

    Node *newHead = head->next;
    temp = head;
    // map random nodes for copy nodes
    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        if (temp->random != nullptr)
        {
            nextNode->random = temp->random->next;
        }
        else
        {
            nextNode->random = nullptr;
        }
        temp = temp->next->next;
    }

    // update the next node for copy node and delete the edge between which was created at first during copy node creation
    temp = head;
    while (temp != nullptr)
    {
        Node *copy = temp->next;
        temp->next = copy->next;
        if (copy->next != nullptr)
        {
            copy->next = temp->next->next;
        }
        temp = temp->next;
    }

    return newHead;
}