#include "../BinaryTreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
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


vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    node<int>* head = NULL;
    node<int>* tail = NULL;
    queue<BinaryTreeNode<int>*> pendingNodes;
    vector<node<int>*> list_;
    if(root == NULL){
        return list_;
    }
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* n = pendingNodes.front();
        if(n == NULL){
            list_.push_back(head);
            head = NULL;
            tail = NULL;
            pendingNodes.pop();
            if(pendingNodes.size() == 0)
                break;
            
            pendingNodes.push(NULL);
        }else{
            if(head == NULL){
                head = new node<int>(n->data);
                tail = head;
            }else{
                tail->next = new node<int>(n->data);
                tail = tail->next;
            }
            if(n->left)
                    pendingNodes.push(n->left);
                
            if(n->right)
                    pendingNodes.push(n->right);
            
            pendingNodes.pop();
        }
    }
    return list_;
}

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
	    print(ans[i]);
    }
}