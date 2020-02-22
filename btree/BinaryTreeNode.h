
template <typename T>
class BinaryTreeNode{
	public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T element){
		this->data = element;
		this->left = NULL;
		this->right = NULL;
	}

	~BinaryTreeNode(){
		delete this->left;
		delete this->right;
	}
};

 class PairAns {
    public :
        int min;
        int max;
 };
