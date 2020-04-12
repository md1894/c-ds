/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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

#include <iostream>
#include <string>
using namespace std;


int char_size[] = {0, 0, 3, 3 ,3 , 3, 3, 4, 3, 4};

string char_set[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};



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























void printKeypad(int num){
    string output = "";
    printkeypad(num, output);
}







int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
