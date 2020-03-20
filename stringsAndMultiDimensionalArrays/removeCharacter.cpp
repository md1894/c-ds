/*
Remove character
Send Feedback
Given a string and a character x. Write a function to remove all occurrences of x character from the given string.
Leave the string as it is, if the given character is not present in the string.

Input format :

Line 1 : Input string

Line 2 : Character x
Sample Input :

welcome to coding ninjas
o

Sample Output :

welcme t cding ninjas


*/

#include <iostream>
using namespace std;


// input - given string
// You need to remove all occurrences of character c that are present in string input.
// Change in the input itself. So no need to return or print anything.

void removeAllOccurrencesOfChar(char a[], char c) {
    // Write your code here
    int j = 0;
    for(int i = 0; a[i] != 0;i++){
        if(a[i] != c){
            a[j] = a[i];
            j++;
        }
    }
    a[j] = 0;
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(input, c);
    cout << input << endl;
}
