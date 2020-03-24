/*
Print Permutations - String
Send Feedback
Given a string, find and print all the possible permutations of the input string.
Note : The order of permutations are not important. Just print them in different lines.
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;


void print_perm(string a, string o){
    if(a.empty()){
        cout<<o<<endl;
        return;
    }
    for(int i = 0; i < a.length(); i++){
        string a1 = a.substr(0,i) + a.substr(i+1,a.length()-i+1);
        string o1 = o + a[i];
        print_perm(a1,o1);
    }
}


void printPermutations(string input){
    string output = "";
    print_perm(input, output);
}

int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
