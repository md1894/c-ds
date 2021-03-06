/*
Level order traversal
Send Feedback
Given a binary tree, print the level order traversal. Make sure each level start in new line.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9
*/

#include "../BinaryTreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* n = pendingNodes.front();
        if(n == NULL){
            cout<<endl;
            pendingNodes.pop();
            if(pendingNodes.size() == 0)
                break;
            
            pendingNodes.push(NULL);
        }else{
            cout<<n->data<<" ";
            if(n->left != NULL)
                pendingNodes.push(n->left);
            
            if(n->right != NULL)
                pendingNodes.push(n->right);
            
            pendingNodes.pop();
        }
    }
}


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

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelATNewLine(root);
}