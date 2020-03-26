// Replace with depth
// Send Feedback
// In a given Generic Tree, replace each node with its depth value. 
// You need to just update the data of each node, no need to return or print anything.
// Input format :
// Line 1 : Elements in level order form separated by space (as per done in class). Order is - 
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Sample Input 1 :
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1 : (Level wise, each level in new line)
// 0 
// 1 1 1 
// 2 2


#include <iostream>
#include <queue>
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


bool containsX(TreeNode<int>* root, int x) {
    
    if(root == NULL){
        return false;
    }else{
        if(root->data == x){
            return true;
        }else{
            bool isPresent = false;
            for(int i = 0; i < root->children.size(); i++){
                isPresent = containsX(root->children[i], x);
                if(isPresent)
                    break;
            }
            return isPresent;
        }
    }
}

int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    if(containsX(root, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
