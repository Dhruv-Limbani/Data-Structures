#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given the head of a linked list of integers, determine the middle node 
    of the linked list. However, if the linked list has an even number of nodes, return the second middle node.
*/

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
        
/*
    Brute force - use stack to store all the elements while traversing LL and then take the elements 
    one by one out of stack from top and put it from start to end of ll.
*/ 

Node* reverseLinkedList(Node *head)
{
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

/*
    Time Complexity: O(2N) This is because we traverse the linked list twice: once to push the values onto the stack, 
    and once to pop the values and update the linked list. Both traversals take O(N) time, hence time complexity  O(2N) ~ O(N).

    Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have 
    all N values,  ie. storing the complete linked list. 
*/


// Optimal Approach 1
/*
    Approach 2: Reverse Links in place (Iterative)

    The previous approach uses O(N) addition space which can be avoided by interchanging the 
    connecting links of the nodes of the linked list in place.


    The main idea is to flip the order of connections in the linked list, which changes the direction of the arrows. 
    When this happens, the last element becomes the new first element of the list. 
    This in-place reversal allows us to efficiently transform the original list without using extra space.

    Algorithm:

    Step 1: Initialise a ‘temp’ pointer at the head of the linked list. This pointer will be used to traverse 
    the linked list. And initialize the pointer ‘prev’ to ‘NULL’ to keep track of the previous node. 
    This will be used to reverse the direction of the ‘next’ pointers.


    Step 2: Traverse the entire linked list by moving through each node using the 'temp' pointer until it 
    reaches the end (marked as 'NULL').

    At each iteration within the traversal,

    Save the reference to the next node that 'temp' is pointing to in a variable called 'front'. 
    This helps retain the link to the subsequent node before altering the 'next' pointer.

    Reverse the direction of the ‘next’ pointer of the current node (pointed to by ‘temp’) to point to the ‘prev’ node. 
    This effectively reversed the direction of the linked list, making the current node point to the previous node. 

    Move the ‘prev’ pointer to the current node. This sets up the ‘prev’ pointer for the next iteration of the loop.
    Move the ‘temp’ pointer to the ‘front’ node. This advances the traversal to the next node in the original order.

*/
Node* reverseLinkedList(Node *head)
{
    Node *prev = NULL, *temp = head;
    while(temp!=NULL){
        Node* temp1 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp1;
    }
    return prev;
}

/*
    TC: O(N)
    SC: O(1)
*/


/*
    Algorithm:

    Base Case:
    Check if the linked list is empty or contains only one node. Return the head as it's already reversed in these cases.


    Recursive Function:
    The core of the algorithm lies in implementing a recursive function responsible for reversing the linked list. 
    This function operates based on the following principle:

    If the base case conditions are not met, the function invokes itself recursively. 
    This recursion continues until it reaches the base case, gradually reversing the linked list starting from 
    the second node (node after it) onward.


    Return

    Following the recursion, the function returns the new head of the reversed linked list. 
    This head marks the last node of the original list before reversal, now the first node in the reversed sequence.


    Steps:

    Step 1: Establish Base Case Conditions: Check if the linked list is either empty or contains only one node. 
    If so, the list is already reversed; hence, return the head as is.

    Step 2: Recursively Reverse the List: Begin the recursive step by reversing the linked list, starting from the second node. 
    Utilise a recursive call to the reverse linked list function, passing the next node as an argument.


    Step 3: Preserve Access to Remaining Nodes: To maintain access to the rest of the linked list while reversing the order, 
    store a reference to the node following the current 'head' node. This step ensures continuity in the link sequence during reversal.

    Step 4: Reverse Link Direction: Adjust the 'front' node to point to the current 'head' node in the reversed order. 
    This action effectively reverses the link between the 'head' node and the 'front' node.

    Step 5: Prevent Cyclic References: Break the link from the current 'head' node to the 'front' node to prevent 
    any cyclic formations. Set 'head->next' to 'NULL' to ensure the reversed segment of the list does not create a loop.

    Step 6: Return the New Head: Finally, return the 'newHead,' which signifies the new head of the reversed linked list. 
    This 'newHead' was initially the last node in the list before the reversal commenced.
*/
// Recursive Optimal Approach
Node* reverseLinkedList(Node *head)
{
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* new_head = reverseLinkedList(head->next);
    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return new_head; 
}

/*
    TC: O(N)
    SC: O(1) 
*/