#include<string>
#include<iostream>
using namespace std;

int int_map(string a){
    if(a.length() == 1){
        return a[0] - 48;
    }else{
        return 10*(a[0] - 48) + (a[1] - 48);
    }
}

char ch[] = {
    0,
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'
};

int main(){
    string a = "5";
    string b = "35";
    string c = "20";
    cout<<a.length()<<endl;
    cout<<a.substr(0,0)+'a'+a.substr(0,a.length())<<endl;
    cout<<a.substr(0,1)+'a'+a.substr(1,a.length())<<endl;
    // cout<<ch[int_map(b)]<<endl;
    // cout<<ch[int_map(c)]<<endl;
    cout<<b.substr(0,0)+'a'+b.substr(0,b.length())<<endl;
    cout<<b.substr(0,1)+'a'+b.substr(1,b.length())<<endl;
    cout<<b.substr(0,2)+'a'+b.substr(2,b.length())<<endl;
    return 0;
}