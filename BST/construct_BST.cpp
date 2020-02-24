/*
    Code: Construct BST from a Sorted Array
    Send Feedback
    Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
    Note : If array size is even, take first mid as root.
    Input format :
    Line 1 : Integer n (Size of array)
    Line 2 : Array elements (separated by space)
    Output Format :
    BST elements (in pre order traversal, separated by space)
    Sample Input :
    7
    1 2 3 4 5 6 7
    Sample Output :
    4 2 1 3 6 5 7 
*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

BinaryTreeNode<int>* constructTree(int *input, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

}

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    
}