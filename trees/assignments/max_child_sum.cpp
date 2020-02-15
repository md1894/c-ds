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

pair<TreeNode<int>*,int > maxSumNode1(TreeNode<int> *root){
    pair <TreeNode<int>*,int > p;
    p.first = root;
    p.second = root->data;
    for(int i = 0; i < root->children.size(); i++){
        p.second += root->children[i]->data;
    }
    for(int i = 0; i < root->children.size(); i++){
        pair <TreeNode<int>*,int > p1 = maxSumNode1(root->children[i]);
        if(p1.second > p.second){
            p.second = p1.second;
            p.first = p1.first;
        }
    }
    return p;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    return (maxSumNode1(root)).first;
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}


