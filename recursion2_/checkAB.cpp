/*
Check AB
Send Feedback
Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Sample Input:
abb
Sample Output:
true
*/

#include <iostream>
using namespace std;


int len(char str[]){
    int i;
    for(i=0; str[i] != 0; i++){
        
    }
    return i;
}

bool checkAB(char a[], int s = 0) {
    if(a[s] == 0){
        return true;
    }
    if(a[s] != 'a'){
        return false;
    }
    if(a[s+1] != 0 && a[s + 2] != 0){
        if(a[s+1] == 'b' && a[s+2] == 'b'){
            return checkAB(a, s +3);
        }    
    }
    
    return checkAB(a, s + 1);
}


int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
