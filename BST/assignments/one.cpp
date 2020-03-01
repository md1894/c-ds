/*
Create & Insert Duplicate Node
Send Feedback
Given a Binary Tree with N number of nodes, for each node create a new duplicate node, and insert that duplicate as left child of the original node.
Note : Root will remain same. So you just need to insert nodes in the given Binary Tree and no need to print or return anything.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Level order traversal of updated tree. (Every level in new line)
Constraints :
1 <= N <= 1000
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output :
8 
8 10 
5 10 
5 6 
2 6 7 
2 7
*/

#include <iostream>
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

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root->left == NULL && root->right == NULL){
        BinaryTreeNode<int>* dup = new BinaryTreeNode<int>(root->data);
        root->left = dup;
        return;
    }else{
        BinaryTreeNode<int>* dup = new BinaryTreeNode<int>(root->data);
        if(root->left)
            insertDuplicateNode(root->left);
        BinaryTreeNode<int>* temp = root->left;
        dup->left = root->left;
        root->left = dup;
        if(root->right)
            insertDuplicateNode(root->right);
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		BinaryTreeNode<int> *first = q.front();
		q.pop();
		if(first == NULL) {
			if(q.empty()) {
				break;
			}
			cout << endl;
			q.push(NULL);
			continue;
		}
		cout << first -> data << " ";
		if(first -> left != NULL) {
			q.push(first -> left);
		}
		if(first -> right != NULL) {
			q.push(first -> right);
		}
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    insertDuplicateNode(root);
    printLevelATNewLine(root);
    delete root;
}
