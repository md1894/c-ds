/*
Return Permutations - String
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
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

void add_char(int step, char c, int end, string output[]){
    int k = 0;
    for(int i = 0; i < end; i = i + step){
        for(int j = i; j < i + step; j++){
            output[j] = output[j].substr(0,k) + c + output[j].substr(k, output[j].length());
        }
        k++;
    }
}

void create_copy(int start, int end, string output[]){
    int step = start;
    for(int i = start; i < end; i++){
        output[i] = output[i-start];
    }
}   



int returnPermutations(string input, string output[]){
   	//base case
    if(input.length() == 1){
        output[0] = input;
        return 1;
    }
    int r = returnPermutations(input.substr(1), output);
    int start = r;
    int end = start*input.length();
    create_copy(start, end, output);
    add_char(r, input[0], end, output);
    return end;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}