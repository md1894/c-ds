// Replace with depth
// Send Feedback
// In a given Generic Tree, replace each node with its depth value. You need to just update the data of each node, no need to return or print anything.
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

void printLevelATNewLine(TreeNode<int> *root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeNode<int> *first = q.front();
        q.pop();
        if(first == NULL) {
            if(q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first -> data << " ";
        for(int i = 0; i < first -> children.size(); i++) {
            q.push(first -> children[i]);
        }
    }
}

void replaceWithDepthValue1(TreeNode<int> *root, int level){
    if(root == NULL)
        return;
    
    root->data = level;
    for(int i = 0; i < root->children.size(); i++){
        replaceWithDepthValue1(root->children[i],level+1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root){    
    replaceWithDepthValue1(root,0);
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}

// sample
//10 3 20 30 40 2 40 50 0 0 0 0 

// TC1
//1 3 20 3 40 1 90 2 50 6 1 100 1 150 17 1000 2000 3000 4000 5000 6000 7000 85 86 87 88 89 92 93 94 95 96 1 80 1 83 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

//TC2
//1 10 10 20 30 40 50 60 70 80 90 100 1 110 1 120 1 130 1 140 1 150 1 160 1 170 1 180 1 190 1 200 1 220 0 0 0 0 0 0 0 0 0 1 230 1 270 2 300 390 0 0
