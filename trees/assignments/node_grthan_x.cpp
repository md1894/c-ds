/*
Count nodes
Send Feedback
Given a tree and an integer x, find and return the number of Nodes which are greater than x.
Input format :
Line 1 : Integer x
Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Count of nodes greater than x
Sample Input 1 :
35
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
3
Sample Input 2 :
10
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
5
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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

int nodesGreaterThanX(TreeNode<int> *root, int x) {
 
    if(root == NULL){
        return 0;
    }else{
        if(root->children.size() == 0){
            if(root->data > x){
                return 1;
            }else{
                return 0;
            }
        }
        int count = 0;
        for(int i = 0;i < root->children.size(); i++){
                count += nodesGreaterThanX(root->children[i], x);
        }
        if(root->data > x)
            count++;
        
        return count;
    }
}


int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    cout << nodesGreaterThanX(root, x) << endl;
}
