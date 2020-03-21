#include <string>
#include "trieNode.h"
using namespace std;

class Trie{
  TrieNode* root;
  
  
  
public:
  Trie(){
      this->root = new TrieNode('\0');
  }
  
private:
  void insertWord(TrieNode* tempRoot, string word){
      //base case
      if(word.size() == 0){
          tempRoot->isTerminal = true;
          return;
      }
      
      // small calculation
      int index = word[0] - 'a';
      TrieNode* child;
      if(tempRoot->children[index] != NULL){
          child = tempRoot->children[index];
      }else{
          // create a new node
          child = new TrieNode(word[0]);
          tempRoot->children[index] = child;
      }
      
      // recursive call;
      insertWord(child, word.substr(1));
  }
  
  bool searchWord(TrieNode* root, string word){
      if(word.size() == 0){
          if(root->isTerminal)
            return true;
          else
            return false;
      }else{
          int index = word[0] - 'a';
          if(root->children[index]){
              return searchWord(root->children[index], word.substr(1));  
          }else{
              return false;
          }
      }
  }

  void removeWord(TrieNode* tempRoot, string word){
      if(word.size() == 0){
          tempRoot->isTerminal = false;
          return;
      }
      int index = word[0] - 'a';
      TrieNode* child;
      if(tempRoot->children[index] != NULL){
          child = tempRoot->children[index];
      }else{
          return;
      }

      removeWord(child, word.substr(1));
      if(child->isTerminal == false){
          for(int i = 0; i < 26; i++){
              if(child->children[i] != NULL){
                  return;
              }
          }
          delete child;
          tempRoot->children[index] = NULL;
      }
  }
  
public:
    void insertWord(string word){
        insertWord(this->root, word);
    }
    
    bool searchWord(string word){
        return searchWord(this->root, word);
    }

    void removeWord(string word){
        removeWord(this->root, word);
    }
};
