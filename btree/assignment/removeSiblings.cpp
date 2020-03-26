/*
Nodes without sibling
Send Feedback
Given a binary tree, print all nodes that don’t have a sibling.
Edit : Print the elements in different lines. And order of elements doesn't matter.
Input format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.
Output format :
Print nodes separated by new line.
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
9    
*/

#include "../BinaryTreeNode.h"
#include <iostream>
#include <queue>
using namespace std;




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

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
        return;
    
    if(root->right == NULL && root->left == NULL)
        return;
    
    if((root->right && root->left == NULL) || (root->left && root->right == NULL)){
         if(root->right)
             cout<<root->right->data<<endl;
        
        if(root->left)
            cout<<root->left->data<<endl;
    }
    
    if(root->left)
        nodesWithoutSibling(root->left);
    
    if(root->right)
        nodesWithoutSibling(root->right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    nodesWithoutSibling(root);
}
