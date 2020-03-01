/*
LCA of Binary Tree
Send Feedback
Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.
Input format :
Line 1 :  Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two integers, Node 1 and Node 2 (separated by space)
Output Format :
LCA
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10
Sample Output 1:
10
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78
Sample Output 3:
-1
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

int lcaBinaryTree(BinaryTreeNode <int>* root , int v1, int v2){
    if(root == NULL)
        return -1;
    
    if(root->data == v1 || root->data == v2){
        return root->data;
    }else{
        int l = lcaBinaryTree(root->left,v1,v2);
        int r = lcaBinaryTree(root->right,v1,v2);
        if(l == -1 && r == -1){
            return -1;
        }else if(r == -1 && l != -1){
            return l;
        }else if(r != -1 && l == -1){
            return r;
        }else if(l != -1 && r != -1){
            return root->data;
        }
    }
}

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    bool isVal1 = isPresent(root, val1);
    bool isVal2 = isPresent(root, val2);
    if(!isVal1 && !isVal2){
        return -1;
    }else if(isVal1 && !isVal2){
        return val1;
    }else if(isVal2 && !isVal1){
        return val2;
    }else{
        return lcaBinaryTree1(root, val1, val2); 
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << lcaBinaryTree(root, a, b);
    delete root;
}
