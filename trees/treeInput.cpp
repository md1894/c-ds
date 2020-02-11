#include<iostream>
#include<queue>
#include "treeNode.cpp"
using namespace std;

int numNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i = 0; i < root->children.size(); i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}


TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root->children.size() != 0){
        int ans = 0;
        TreeNode<int>* max = root;
        for(int i = 0; i < root->children.size(); i++){
            TreeNode<int>* node1 = maxDataNode(root->children[i]);
            if(max->data < node1->data)
                max = node1;
        }
        return max;
    }else{
        return root;
    }
}


void postOrder(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output in specified format.
     */
    if(root == NULL){
        return;
    }
    
    if(root->children.size() == 0){
        cout<<root->data<<" ";
    }else{
        for(int i = 0; i < root->children.size(); i++){
             postOrder(root->children[i]);   
        }
        cout<<root->data<<" ";
    }
}

int sumOfNodes(TreeNode<int>* root) {
    if(root->children.size() != 0){
        int ans = 0;
        for(int i = 0; i < root->children.size(); i++){
            ans += sumOfNodes(root->children[i]);
        }
        ans += root->data;
        return ans;
    }else{
        return root->data;;
    }
}

void levelOrderPrint(TreeNode<int>* root){
    if(root == NULL)           //this is a edge case not a base case
        return;
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* frontNode = pendingNodes.front();
        cout<<frontNode->data<<" : ";
        for(int i = 0; i < frontNode->children.size(); i++){
            cout<<frontNode->children[i]->data<<",";
            pendingNodes.push(frontNode->children[i]);
        }
        cout<<endl;
        pendingNodes.pop();
    }
}

int numLeafNodes(TreeNode<int>* root) {
    if(root != NULL){
        if(root->children.size() == 0){
            return 1;
        }
        int n = 0;
        for(int i = 0; i < root->children.size(); i++){
            n += numLeafNodes(root->children[i]);
        }
        return n;
    }else{
        return 0;
    }
}

void printAtLevelK(TreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<endl;
    }
    for(int i = 0; i < root->children.size(); i++){
        printAtLevelK(root->children[i], k - 1);
    }
}

int height(TreeNode<int>* root) {
       if(root->children.size() != 0){
        int ans = 0;
        int maxHeight = 1;
        for(int i = 0; i < root->children.size(); i++){
            ans = height(root->children[i]);
            if(ans>maxHeight)
                maxHeight = ans;
        }
        return 1 + maxHeight;
    }else{
        return 1;
    }
}

void print(TreeNode<int>* root){
    if(root == NULL)           //this is a edge case not a base case
        return;

    cout<<root->data<<":";
    for(int i = 0; i < root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0; i < root->children.size(); i++){
        print(root->children[i]);
    }
}

TreeNode<int>* takeInputLevelWise(){
    int rootdata;
    cout<<"Enter the root data : "<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter Number of childrenren of "<<frontNode->data<<endl;
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            int childrenData;
            cout<<"Enter children Number "<<i + 1<<" of "<<frontNode->data<<endl;
            cin>>childrenData;
            TreeNode<int>* children = new TreeNode<int>(childrenData);
            frontNode->children.push_back(children);
            pendingNodes.push(children);
        }
    }
    return root;
}

TreeNode<int>* takeInput(){
    int rootdata;
    cout<<"Enter the root data : "<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter the number of childrenren : "<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        TreeNode<int>* nd = takeInput();
        root->children.push_back(nd);
    }
    
    return root;
}

int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // TreeNode<int>* root = takeInput();
    TreeNode<int>* root = takeInputLevelWise();
    levelOrderPrint(root);
    cout<<"Number Of Nodes are "<<numNodes(root)<<endl;
    return 0;
}
