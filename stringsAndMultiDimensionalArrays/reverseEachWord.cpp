/*
Reverse Each Word
Send Feedback
Given a string S, reverse each word of a string individually. For eg. if a string is "abc def", reversed string should be "cba fed".
Input Format :

String S

Output Format :

Updated string

Constraints :
1 <= Length of S <= 1000
Sample Input :

Welcome to Coding Ninjas

Sample Output:

emocleW ot gnidoC sajniN

 
*/

#include <iostream>
using namespace std;

// input - given string
// Update in the given input itself. No need to return or print anything

void swap(char a[],int i,int j){
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void reverseEachWord(char a[]) {
    // Write your code here
    int start,end,j=0;
    for(int i = 0; a[i] != 0; i++){
        start = i;
        end = i;
        while(a[end] != 32 && a[end] != 0){
            end++;
        }
        if(a[end] != 0){
            i = end;
        }else{
            i = end - 1;
        }
        end--;
        while(start < end){
            swap(a,start,end);
            start++;
            end--;
        }
    }
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}
