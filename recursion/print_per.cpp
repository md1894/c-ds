#include <iostream>
#include <string>
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
    string a;
    cin>>a;
    printPermutations(a);
    return 0;
}