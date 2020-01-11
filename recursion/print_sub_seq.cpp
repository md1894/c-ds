#include<string>
#include<iostream>
using namespace std;

void print_sub_seq(string a, string op){
    if(a.length() == 0){
        cout<<op<<endl;
        return;
    }
    print_sub_seq(a.substr(1), op);
    print_sub_seq(a.substr(1), op + a[0]);
}

int main(){
    string a, op = "";
    cin>>a;
    print_sub_seq(a,op);
    return 0;
}