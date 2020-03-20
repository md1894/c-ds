/*
Check Permutation
Send Feedback
Given two strings, check if they are permutations of each other. Return true or false.
Permutation means - length of both the strings should same and should contain same set of characters. Order of characters doesn't matter.
Note : Input strings contain only lowercase english alphabets.
Input format :

Line 1 : String 1
Line 2 : String 2

Sample Input 1 :

abcde
baedc

Sample Output 1 :

true

Sample Input 2 :

abc
cbd

Sample Output 2 :

false


*/

#include <iostream>
using namespace std;


// input1 - first input string
// input2 - second input string

int len(char s[]){
    int i;
    for(i = 0; s[i] != 0;i++){}
    return i;
}

void swap(char s[],int i,int j){
    char temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

bool isPermutation(char input1[], char input2[]) {
    int i = len(input1);
    int j = len(input2);
    if(--i != --j){
        return false;
    }else{
        for(int a = 0; input1[a]!=0; a++){
            for(int b = 0; input2[b]!=0; b++){
                if(input1[a] == input2[b]){
                    input2[b] = 0;
                    swap(input2,b,i);
                    i--;
                    break;
                }
            }
        }
    }
    if(input2[0] == 0){
        return true;
    }else{
        return false;
    }
}


int main() {
    char input1[1000], input2[1000];
    cin.getline(input1, 1000);
    cin.getline(input2, 1000);
    if(isPermutation(input1, input2) == 1) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}
