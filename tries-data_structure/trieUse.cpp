#include "trie.h"
#include <iostream>
using namespace std;

int main(){
  Trie t;
  t.insertWord("are");
  t.insertWord("and");
  bool b = t.searchWord("are");
  if(b){
      cout<<"are Found"<<endl;
  }
  if(t.searchWord("and")){
      cout<<"art Found"<<endl;
  }
  return 0;
}
