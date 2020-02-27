/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. Return the head of LL.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Linked list elements (separated by space)
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output :
2 5 6 7 8 10
*/


#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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


pair<Node<int>*, Node<int>*> constructBST1(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<Node<int>*, Node<int>*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }else{
        Node<int>* nw = new Node<int>(root->data);
        Node<int>* head = NULL;
        Node<int>* tail = NULL;
        pair<Node<int>*, Node<int>*> lp = constructBST1(root->left);
        if(lp.first == NULL && lp.second == NULL){
            lp.first = nw;
            lp.second = nw;
        }else{
            lp.second->next = nw;
            lp.second = lp.second->next;
        }
        head = lp.first;
        tail = lp.second;
        pair<Node<int>*, Node<int>*> rp = constructBST1(root->right);
        tail->next = rp.first;
        if(rp.second)
            tail = rp.second;
        pair<Node<int>*, Node<int>*> fp;
        fp.first = head;
        fp.second = tail;
        return fp;
    }
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    return constructBST1(root).first;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}
