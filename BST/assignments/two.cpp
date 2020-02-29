/*
Pair sum BInary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S
Output Format :
Each pair in different line (pair elements separated by space)
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

#include <iostream>
#include <queue>
#include <vector>
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
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
    }
};

void merge(vector<int>* v, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = (*v)[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = (*v)[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            (*v)[k] = L[i]; 
            i++; 
        } 
        else
        { 
            (*v)[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        (*v)[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        (*v)[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(vector<int>* v, int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(v, l, m); 
        mergeSort(v, m+1, r); 
  
        merge(v, l, m, r); 
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
/*
int len(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }else{
        int l = len(root->left);
        int r = len(root->right);
        return 1 + l + r;
    }
}*/


void get_tree_in_vector(vector<int>* ve,BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }else{
        ve->push_back(root->data);
        get_tree_in_vector(ve, root->left);
        get_tree_in_vector(ve, root->right);
    }
}

void print_pair_sum(vector<int>* v, int start, int end, int sum){
    if(start >= end)
        return;
    
    int sum1 = (*v)[start] + (*v)[end];
    if(sum1 == sum){
        cout<<(*v)[start]<<" "<<(*v)[end]<<" "<<endl;
        print_pair_sum(v, start + 1, end - 1, sum);
    }else if(sum1 > sum){
        print_pair_sum(v, start, end - 1, sum);
    }else{
        print_pair_sum(v, start + 1, end, sum);
    }
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
//     int t_len = len(root);
    vector<int> ve;
    get_tree_in_vector(&ve,root);
    mergeSort(&ve, 0, ve.size() - 1);
    print_pair_sum(&ve, 0, ve.size() - 1, sum);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
