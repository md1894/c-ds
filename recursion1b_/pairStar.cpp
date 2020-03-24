/*
Pair star
Send Feedback
Given a string, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
xxyy
Sample Output 2:
x*xy*y
Sample Input 3 :
aaaa
Sample Output 3:
a*a*a*a
*/

#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.

int len(char a[]){
    int i;
    for(i=0;a[i] != 0; i++){
        
    }
    return i;
}

void shift(char a[]){
    int l = len(a),i;
    for(i = l; i >= 1; i--){
        a[i] = a[i-1];
    }
    a[0] = '*';
    a[l+1] = 0;
}

void pairStar(char a[]) {
    // Write your code here
    int l = len(a);
    if(l>=2){
        pairStar(a+1);
        if(a[0] == a[1]){
            shift(a+1);
        }
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}