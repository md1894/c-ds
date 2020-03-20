
class TrieNode{
public:
    char data;
    TrieNode** children;
    bool isTerminal;
    
    TrieNode(char data){
	this->data = data;
	this->children = new TrieNode*[26];
	this->isTerminal = false;
      for(int i = 0; i < 26; i++){
	  this->children[i] = NULL;
      }
    }
};