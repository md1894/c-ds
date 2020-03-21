#include "trie.h"
#include <iostream>
using namespace std;



int main() {
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << t.searchWord("and") << endl;

	t.removeWord("and");
	cout << t.searchWord("and") << endl;
  cout << t.searchWord("pot") << endl;
  return 0;
}
