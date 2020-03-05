/*
Pair sum in a BST
Send Feedback
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).
Assume BST contains all unique elements.
Note: In a pair, print the smaller element first.
Input format:

Line 1: Elements in the level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2: S

Output format: Each pair in a different line (pair elements separated by space)

Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output
2 10
5 7

10 8 21 4 9 13 28 1 6 -1 -1 12 -1 23 -1 -1 -1 5 7 -1 -1 -1 24 -1 -1 -1 -1 -1 -1 
25
*/

#include <iostream>
#include <queue>
#include <stack>
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

int cnt(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }else{
        return cnt(root->left) + cnt(root->right) + 1;
    }
}


void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if(root == NULL){
          return;
    }
    stack<BinaryTreeNode<int>*> inOrder;
    stack<BinaryTreeNode<int>*> RevInOrder;
    BinaryTreeNode<int>* temp = root;
    int countOfNodes = cnt(root);
    int count = 0;
    while(temp != NULL){
        RevInOrder.push(temp);
        temp = temp->right;
    }
    temp = root;
    while(temp != NULL){
        inOrder.push(temp);
        temp = temp->left;
    }
    while(count != countOfNodes){
        BinaryTreeNode<int>* top1 = inOrder.top();
        BinaryTreeNode<int>* top2 = RevInOrder.top();
        BinaryTreeNode<int>* top = top1;
        if(top1->data + top2->data == s){
            cout<<top1->data<<" "<<top2->data<<endl;
            inOrder.pop();
            count++;
            if(top->right != NULL){
                top = top->right;
                while(top != NULL){
                    inOrder.push(top);
                    top = top->left;
                }
            }
            top = top2;
            RevInOrder.pop();
            count++;
            if(top->left != NULL){
                top = top->left;
                while(top != NULL){
                    inOrder.push(top);
                    top = top->right;
                }
            }
        }else if(top1->data + top2->data > s){
            top = top2;
            RevInOrder.pop();
            count++;
            if(top->left != NULL){
                top = top->left;
                while(top != NULL){
                    RevInOrder.push(top);
                    top = top->right;
                }
            }
        }else{
            top = top1;
            inOrder.pop();
            count++;
            if(top->right != NULL){
                top = top->right;
                while(top != NULL){
                    inOrder.push(top);
                    top = top->left;
                }
            }
        }
    }
}




int main() {
    BinaryTreeNode<int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
