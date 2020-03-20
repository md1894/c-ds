/*
Check Palindrome (recursive)
Send Feedback
Check if a given String S is palindrome or not (using recursion). Return true or false.
Input Format :

String S

Output Format :

true or false

Sample Input 1 :

racecar

Sample Output 1:

true

Sample Input 2 :

ninja

Sample Output 2:

false


*/

#include <iostream>
using namespace std;


int len(char a[]){
    int i;
    for(i=0;a[i]!=0;i++){
        
    }
    return i-1;
}

bool checkPalindrome(char input[], int s=0, int e=-1) {
    // Write your code here
    if(e == -1){
        e = len(input);
    }
    if (s < e){
        if(input[s] == input[e]){
            return checkPalindrome(input,s+1,e-1);
        }else{
            return false;
        }
    }else{
        return true;
    }
}




int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
