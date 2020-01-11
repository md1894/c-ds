#include<iostream>
#include<string>
#include "key.h"
using namespace std;

void printkeypad(int num, string op){
    if(num == 0){
        cout<<op<<endl;
        return;
    }
    string c = char_set[num%10];
    printkeypad(num/10, c[0] + op);
    printkeypad(num/10, c[1] + op);
    printkeypad(num/10, c[2] + op);
    if(char_size[num%10] == 4){
        printkeypad(num/10, c[3] + op);
    }
    
}

int main(){
    string op = "";
    int a;
    cin>>a;
    printkeypad(a,op);
    return 0;
}