/*
Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/

#include <iostream>
#include <queue>
#include <climits>
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

class bunch{
    public:
        int min;
        int max;
        bool isBST;
        int heightOfMaxBST;
};

bunch largestBSTSubtree1(BinaryTreeNode<int>* root){
    if(root == NULL){
        bunch ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        ans.heightOfMaxBST = 0;
        return ans;
    }else{
        bunch leftBunch = largestBSTSubtree1(root->left);
        bunch rightBunch = largestBSTSubtree1(root->right);
        bunch ans;
        ans.min = min(root->data, min(leftBunch.min, rightBunch.min));
        ans.max = max(root->data, min(leftBunch.max, rightBunch.max));
        ans.isBST = leftBunch.isBST && rightBunch.isBST && (leftBunch.max < root->data) 
            && (rightBunch.min > root->data);
        if(ans.isBST){
            ans.heightOfMaxBST = max(leftBunch.heightOfMaxBST, rightBunch.heightOfMaxBST) + 1;
        }else{
            ans.heightOfMaxBST = max(leftBunch.heightOfMaxBST, rightBunch.heightOfMaxBST);
        }
        return ans;
    }
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
     return largestBSTSubtree1(root).heightOfMaxBST;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
