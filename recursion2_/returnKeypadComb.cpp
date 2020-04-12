/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using 
digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

#include <string>
using namespace std;

int char_size[] = {0, 0, 3, 3 ,3 , 3, 3, 4, 3, 4};

string char_set[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void create_copy(string str[], int n, int size){
    for(int i = size; i < size*n; i++){
        str[i] = str[i - size];
    }
}

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }
    int smallOutputSize = keypad(num/10, output);
    string currentCharSet = char_set[num % 10];
    int currentCharSetSize = char_size[num % 10];
    create_copy(output, currentCharSetSize, smallOutputSize);
    for(int i = 0; i < currentCharSetSize; i++){
        int step = i*smallOutputSize;
        for(int j = step; j < (i+1)*smallOutputSize; j++){
            output[j] += currentCharSet[i];
        }
    }
    return currentCharSetSize*smallOutputSize;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
