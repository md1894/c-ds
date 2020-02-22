#include<iostream>
#include<queue>
#include <climits>
#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;


bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    bool isPresent;
    if(root == NULL)
        return false;
    
    if(root->data == x){
        return true;
    }else{
        isPresent = isNodePresent(root->left,x);
        if(isPresent)
            return isPresent;
        else{
            return isNodePresent(root->right,x);
        }
    }
}

PairAns minMax(BinaryTreeNode<int> *root) {
	if(root==NULL){
		PairAns ans;
		ans.min = INT_MAX;
		ans.max = INT_MIN;
		return ans;
	}
	PairAns leftAns = minMax(root->left);
	PairAns rightAns = minMax(root->right);
	PairAns myAns;
	myAns.max = max(leftAns.max,max(rightAns.max,root->data));
	myAns.min = min(leftAns.min,min(rightAns.min,root->data));
	return myAns;
}

void preOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        cout<<-1<<" ";
    }else{
        cout<<root->data<<" ";
        if(root->left){
            preOrder(root->left);
        }
        if(root->right){
            preOrder(root->right);
        }
    }
}

/*
  This function will generate The BinaryTree from inorder traversal dataset and preorder traversal dataset
*/
BinaryTreeNode<int>* helperGenerateBTree(int* in, int* pre, int inS, int inE, int preS, int preE){
	// Base Case
	if(inS > inE){
		return NULL;
	}
	int rootData = pre[preS];
	int rootIndex = -1;
	for(int i = inS; i <= inE; i++)
	{
		if(rootData == in[i])
		{
			rootIndex = i;
			break;
		}
	}
	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rInS = rootIndex + 1;
	int rInE = inE;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = helperGenerateBTree(in, pre, lInS, lInE, lPreS, lPreE);
	root->right =  helperGenerateBTree(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

/*
  This function will generate The BinaryTree from inorder traversal dataset and postorder traversal dataset
*/
BinaryTreeNode<int>* helperGenerateBTree1(int* in, int* pos, int inS, int inE, int posS, int posE){
	// Base Case
	if(inS > inE){
		return NULL;
	}
	int rootData = pos[posE];
	int rootIndex = -1;
	for(int i = inS; i <= inE; i++)
	{
		if(rootData == in[i])
		{
			rootIndex = i;
			break;
		}
	}
	int lInS = inS;
	int lInE = rootIndex - 1;
	int lposS = posS;
	int lPosE = lInE - lInS + lposS;
	int rInS = rootIndex + 1;
	int rInE = inE;
	int rPosS = lPosE + 1;
	int rPosE = posE - 1;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = helperGenerateBTree1(in, pos, lInS, lInE, lposS, lPosE);
	root->right =  helperGenerateBTree1(in, pos, rInS, rInE, rPosS, rPosE);
	return root;
}

void postOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        cout<<-1<<" ";
        return;
    }
    if(root->left){
        postOrder(root->left);
    }
    if(root->right){
        postOrder(root->right);
    }
    cout<<root->data<<" ";
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }else{
        BinaryTreeNode<int>* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorBinaryTree(root->left);
        mirrorBinaryTree(root->right);
    }
}

int height(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return 1;
    }
    if(root->right || root->left){
        int a1 = 1 + height(root->left);
        int a2 = 1 + height(root->right);
        return a1>a2?a1:a2;
    }
}

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

// print -1 when node is not present

void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    if(root == NULL)
        return;
    
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* nd = pendingNodes.front();
        cout<<nd->data<<":";
        if(nd->left){
            cout<<"L:"<<nd->left->data<<",";
            pendingNodes.push(nd->left);
        }else{
            cout<<"L:"<<-1<<",";
        }
        if(nd->right){
            cout<<"R:"<<nd->right->data;
            pendingNodes.push(nd->right);
        }else{
            cout<<"R:"<<-1;
        }
        cout<<endl;
        pendingNodes.pop();
    }
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
// 	BinaryTreeNode<int>* root = takeInputLevelWise();
// 	print(root);
// 	delete root;
    int in[] = {4,2,5,1,8,6,9,3,7};
    int pre[] = {1,2,4,5,3,6,8,9,7};
    BinaryTreeNode<int>* root = helperGenerateBTree(in,pre,0,8,0,8);
    printLevelWise(root);
	return 0;
}
