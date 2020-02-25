#include <climits>
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
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
/*************************************************************************************************/
// class pair1{
//     public:
//     bool isBst;
//     int min;
//     int max;
// };

// pair1 isBST1(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         pair1 p;
//         p.min = INT_MAX;
//         p.max = INT_MIN;
//         p.isBst = true;
//         return p;
//     }
//     pair1 leftNode = isBST1(root->left);
//     pair1 rightNode = isBST1(root->right);
//     pair1 ans;
//     ans.min = min(root->data, min(leftNode.min, rightNode.min));
//     ans.max = max(root->data, max(leftNode.max, rightNode.max));
//     ans.isBst = leftNode.max < root->data && rightNode.min > root->data && leftNode.isBst && rightNode.isBst;
//     return ans;
// }

// bool isBST(BinaryTreeNode<int> *root){
//     return isBST1(root).isBst;
// }
/*************************************************************************************************/
// This is the worst solution

// int minimum(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         return INT_MAX;
//     }

//     return min(root->data, min(minimum(root->left), minimum(root->right)));
// }

// int maximum(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         return INT_MIN;
//     }
//     return max(root->data, max(maximum(root->left), maximum(root->right)));
// }

// bool isBST(BinaryTreeNode<int> *root){
//     if(root == NULL)
//         return true;
    
//     int leftMax = maximum(root->left);
//     int rightMin = minimum(root->right);
//     bool isBst = root->data > leftMax && root->data < rightMin && isBST(root->left) & isBST(root->right);
//     return isBst;
// }
/*************************************************************************************************/

bool isBST1(BinaryTreeNode<int>* root, int Max = INT_MAX, int Min = INT_MIN){
    if(root == NULL)
        return true;

    if(root->data < Min || root->data > Max)
        return false;
    
    bool isLeftOk = isBST1(root->left, root->data - 1,Min);
    bool isRightOk = isBST1(root->right, Max, root->data);
    return isLeftOk && isRightOk;
}

bool isBST(BinaryTreeNode<int> *root){
    return isBST1(root);
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}