// #include "TrieNode.h"
#include <string>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

    
    bool search_(TrieNode* tempRoot, string pattern){
        if(pattern.size() == 0){
            return true;
        }else{
            int index = pattern[0] - 'a';
            TrieNode* child;
            if(tempRoot->children[index] != NULL){
                child = tempRoot->children[index];
                return search_(child, pattern.substr(1));
            }else{
                return false;
            }
        }        
    }

	void autoComplete_(TrieNode* tempRoot, string ans, string pattern){
        if(pattern.size() == 0){
            if(tempRoot->isTerminal == true){
                cout<<ans<<endl;
            }
            for(int i = 0; i < 26; i++){
                if(tempRoot->children[i]){
                    string updatedPattern = ans + tempRoot->children[i]->data;
                    autoComplete_(tempRoot->children[i], updatedPattern, pattern);
                }
            }
        }else{
            int index = pattern[0] - 'a';
            TrieNode* child;
            if(tempRoot->children[index] != NULL){
                child = tempRoot->children[index];
                ans += child->data;
                autoComplete_(child, ans, pattern.substr(1));
            }
        }
    }
    
	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	bool patternMatching(vector<string> vect, string pattern) {
		// Complete this function
		// Return true or false
        for(int i = 0; i < vect.size(); i++){
            string str = vect[i];
            while(str.size() != 0){
                string temp = str.substr(1);
                insertWord(temp);
                str = temp;
            }
        }
        return search_(this->root, pattern);
	}

    bool findIfPalindromePair(vector<string> vect) {
        for(int i = 0; i < vect.size(); i++){
            string str = vect[i];
            while(str.size() != 0){
                string temp = str.substr(1);
                insertWord(temp);
                str = temp;
            }
        }
        for(int i = 0; i < vect.size(); i++){
            string str = vect[i]; 
            reverse(str.begin(), str.end());
            if(search_(this->root, str) == true){
                return true;
            }else{
                string str1 = vect[i].substr(1);
                reverse(str1.begin(), str1.end());
                if(search_(this->root, str1) == true){
                    return true;
                }
            }
        }
        return false;
	}

	void autoComplete(vector<string> input, string pattern) {
		// Complete this function
		// Print the output as specified in question
		for(int i = 0; i < input.size(); i++){
			insertWord(input[i]);
		}
		string ans = "";
		autoComplete_(this->root, ans, pattern);
	}
};













