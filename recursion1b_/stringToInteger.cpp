/*
String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string (string, Eg. "1234")
Output format :
Corresponding integer (int, Eg. 1234)
Sample Input 1 :
1231
Sample Output 1:
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/

#include <iostream>
using namespace std;


int conv(char a){
    return a - 48;
}


int len(char a[]){
    int i;
    for(i=0;a[i] != 0; i++){
        
    }
    return i;
}

int p(int i, int j){
    if(j == 0)
        return 1;
    else
        return i*p(i,j-1);
}

int stringToNumber(char a[]) {
    // Write your code here
    int l = len(a);
    if(l == 1)
        return conv(a[0]);
    else{
        int n = conv(a[0]);
        return n*p(10,l-1) + stringToNumber(a+1);
    }
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}