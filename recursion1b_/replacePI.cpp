/*
Replace pi (recursive)
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
*/

#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

int len(char a[]){
    int i;
    for(i=0;a[i] != 0; i++){
        
    }
    return i;
}

void shift(char a[]){
    int i;
    for(i = len(a); i >=0; i--){
        a[i+2] = a[i];
    }
    
}

void replacePi(char a[]) {
	// Write your code here
    if(a[0]!=0){
        replacePi(a+1);
        if(a[0] == 'p' && a[1] == 'i'){
            shift(a);
            a[0] = '3';
            a[1] = '.';
            a[2] = '1';
            a[3] = '4';
        }
    }else{
        return;
    }
}


int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}