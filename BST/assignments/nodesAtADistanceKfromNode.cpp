/*
Print nodes at distance k from node
Send Feedback
Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : Node

Line 3 : K

Output format : Answer nodes in different line

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3
1
Sample Output :
9
6
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



BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printNodeAtDepthK(BinaryTreeNode<int>* root, int depth){
    if(root == NULL)
        return;
    if(depth == 0){
        cout<<root->data<<endl;
        return;
    }else if(depth > 0){
        printNodeAtDepthK(root->left, depth - 1);
        printNodeAtDepthK(root->right, depth - 1);
    }
}

int printN(BinaryTreeNode<int> *root, int node, int k){
  // Base Case 1: If tree is empty, return -1 
    if (root == NULL) return -1; 
  
    // If target is same as root.  Use the downward function 
    // to print all nodes at distance k in subtree rooted with 
    // target or root 
    if (root->data == node) 
    { 
        printNodeAtDepthK(root, k); 
        return 0; 
    } 
  
    // Recur for left subtree 
    int dl = printN(root->left, node, k); 
  
    // Check if target node was found in left subtree 
    if (dl != -1) 
    { 
         // If root is at distance k from target, print root 
         // Note that dl is Distance of root's left child from target 
         if (dl + 1 == k) 
            cout << root->data << endl; 
  
         // Else go to right subtree and print all k-dl-2 distant nodes 
         // Note that the right child is 2 edges away from left child 
         else
            printNodeAtDepthK(root->right, k-dl-2); 
  
         // Add 1 to the distance and return value for parent calls 
         return 1 + dl; 
    } 
  
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE 
    // Note that we reach here only when node was not found in left subtree 
    int dr = printN(root->right, node, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            cout << root->data << endl; 
         else
            printNodeAtDepthK(root->left, k-dr-2); 
         return 1 + dr; 
    } 
  
    // If target was neither present in left nor in right subtree 
    return -1; 
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    printN(root, node, k);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
