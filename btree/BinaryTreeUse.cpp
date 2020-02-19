#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

void print(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;

	cout<<root->data<<":";
	if(root->left){
		cout<<" L "<<root->left->data;
	}
	if(root->right){
		cout<<" R "<<root->right->data;
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	BinaryTreeNode<int>* root = NULL;
	queue<BinaryTreeNode<int>*> pendingNodes;
	cout<<"Enter Root Data "<<endl;
	cin>>rootData;
	if(rootData != -1){
		root = new BinaryTreeNode<int>(rootData);
		pendingNodes.push(root);
		while(pendingNodes.size() != 0){
			BinaryTreeNode<int>* frontNode = pendingNodes.front();
			int data;
			cout<<"Enter Left Child Data for Node "<<frontNode->data<<endl;
			cin>>data;
			if(data != -1){
				BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(data);
				frontNode->left = leftChild;
				pendingNodes.push(leftChild);
			}
			cout<<"Enter Right Child Data for Node "<<frontNode->data<<endl;
			cin>>data;
			if(data != -1){
				BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(data);
				frontNode->right = rightChild;
				pendingNodes.push(rightChild);
			}
			pendingNodes.pop();
		}
	}
	return root;
}


BinaryTreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter Data "<<endl;
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* lChild = takeInput();
	BinaryTreeNode<int>* rChild = takeInput();
	root->left = lChild;
	root->right = rChild;
	return root;
}

int main(){
	/*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* left = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* right = new BinaryTreeNode<int>(3);
	root->left = left;
	root->right = right;*/
	/*BinaryTreeNode<int>* root = takeInput();*/
	BinaryTreeNode<int>* root = takeInputLevelWise();
	print(root);
	delete root;
	return 0;
}
