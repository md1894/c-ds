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

bool isPresent(BinaryTreeNode<int>* root, int x){
    if(root == NULL){
        return false;
    }else if(root->data == x){
        return true;
    }else if(root->data < x){
        return isPresent(root->right, x);
    }else{
        return isPresent(root->left, x);
    }
}

int lcaBinaryTree1(BinaryTreeNode <int>* root , int val1, int val2){
}

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    bool isVal1 = isPresent(root, val1);
    bool isVal2 = isPresent(root, val2);
    if(!isVal1 && !isVal2){
        return -1;
    }else if(isVal1){
        return val1;
    }else if(isVal2){
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
