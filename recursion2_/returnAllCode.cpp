/*
Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <iostream>
// #include "solution.h"
using namespace std;

#include <string>
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

int getCodes(string input, string output[10]) {
   if(input.length() == 0){
       output[0] = "";
       return 1;
   }
   string o1[10], o2[10];
   int r1 = getCodes(input.substr(1), o1);
   int i1,i2 = 0;
   i1 = int_map(input.substr(0,1));
   i2 = int_map(input.substr(0,2));
   int r2 = 0;
   char c1 = ch[i1];
   char c2 = 0;
   if(input.length() >= 2 && (i2 >= 10 && i2 <= 26)){
        c2 = ch[i2];
        r2 = getCodes(input.substr(2), o2);
    }
    for(int i = 0; i < r1; i++){
        output[i] = c1 + o1[i];
    }
    if(r2 != 0 && (i2 >= 10 && i2 <= 26)){
        for(int j = r1; j < r1 + r2; j++){
            output[j] = c2 + o2[j-r1];
        }
    }
    return r1 + r2;
}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}