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


BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL){
        return NULL;
    }
    
    if(k == root->data){
        return root;
    }
    
    if(k > root->data){
        return searchInBST(root->right,k);
    }else{
        return searchInBST(root->left,k);
    }
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if(root == NULL){
        return;
    }
    
    if(root->data >= k1){
        elementsInRangeK1K2(root->left,k1,k2);
    }
    
    if(root->data >= k1 && root->data <= k2){
        cout<<root->data<<" ";
    }
    
    if(root->data <= k2){
        elementsInRangeK1K2(root->right,k1,k2);
    }
    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    /*
    int k;
    cin >> k;
    BinaryTreeNode<int> *ans = searchInBST(root, k);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    */
    
    /*
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
    */
    delete root;
}
