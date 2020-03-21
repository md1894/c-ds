
/*
Palindrome Pair
Send Feedback
Givan n number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
Return true or false.
Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)
Output Format :
true ot false
Sample Input 1 :
4
abc def ghi cba
Sample Output 2 :
true
Sample Output 1 Expalanation :
"abc" and "cba" forms a palindrome
Sample Input 2 :
4
abc def ghi hg
Sample Output 2 :
true
Sample Output 2 Expalanation :
"ghi" and "hg" forms a palindrome

*/


#include <iostream>
#include <string>
using namespace std;
#include "trie.h"
#include <vector>


int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    
    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}