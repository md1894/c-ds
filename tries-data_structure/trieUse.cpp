#include "trie.h"
#include <iostream>
using namespace std;

int main(){
  Trie t;
  t.insertWord("mehul");
  t.insertWord("meher");
  bool b = t.searchWord("mehul");
  if(b){
      cout<<"Mehul Found"<<endl;
  }
  if(t.searchWord("jayashree")){
      cout<<"Jaya Found"<<endl;
  }
  return 0;
}
