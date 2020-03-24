/*
Print all Codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
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

void printAllCodes(string input, string output){
    //base case
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    string output1, output2;
    int i1 = int_map(input.substr(0,1));
    char c1 = ch[i1];
    int i2 = int_map(input.substr(0,2));
    char c2 = ch[i2];
    printAllCodes(input.substr(1), (string)(output + c1));
    if(i2 >= 10 && i2 <= 26){
        printAllCodes(input.substr(2), (string)(output + c2));
    }
}


void printAllPossibleCodes(string input) {
    string output;
    printAllCodes(input, output);
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}