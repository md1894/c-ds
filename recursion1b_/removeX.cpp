/*
Remove X
Send Feedback
Given a string, compute recursively a new string where all 'x' chars have been removed.
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:


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

void rem(char a[]){
    int i = len(a),j;
    for(j = 0; j < i; j++){
        a[j] = a[j+1];
    }
    a[j] = 0;
}

void removeX(char a[]) {
    // Write your code here
    if(a[0] != 0){
        removeX(a+1);
        if(a[0] == 'x'){
            rem(a);
        }
    }
}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
