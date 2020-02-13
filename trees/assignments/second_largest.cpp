
// Second Largest Element In Tree

// Given a generic tree, find and return the node with second largest value in given tree. 
// Return NULL if no node with required value is present.
// Input format :
// Line 1 : Elements in level order form separated by space (as per done in class). Order is -
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Output Format :
// Second Largest node data
// Sample Input 1 :
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1 :
// 40

#include <queue>
#include <climits>
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

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}

//sample input
//10 3 20 30 40 2 40 50 0 0 0 0 

// TC1
// 1 3 20 3 40 1 90 2 50 6 1 100 1 150 17 1000 2000 3000 4000 5000 6000 7000 85 86 87 88 89 92 93 94 95 96 1 80 1 83 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 6000