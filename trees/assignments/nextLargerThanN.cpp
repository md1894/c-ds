/*
Next larger
Send Feedback
Given a generic tree and an integer n. 
Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.
Return NULL if no node is present with the value greater than n.
Input Format :
Line 1 : Integer n
Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Node with value just greater than n.
Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
20
Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
30
*/

#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>
#include <climits>

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    TreeNode<int>* target = NULL;
    if(root->data > n){
        target = root;
    }
    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>* n1 = nextLargerElement(root->children[i],n);
        if(n1 != NULL){
            if(n1->data > n){
                if(target == NULL){
                    target = n1;
                }else{
                    if(target->data > n1->data){
                        target = n1;
                    }
                }
            }
        }
    }
    return target;
}


int main() {
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}
