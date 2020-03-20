/*
Compress the String
Send Feedback
Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
Note : Consecutive count of every character in input string is less than equal to 9.
Input Format :

Input string S

Output Format :

Compressed string 

Sample Input:

aaabbccdsa

Sample Output:

a3b2c2dsa


*/

#include <iostream>
using namespace std;


// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.

void stringCompression(char a[]) {
    // Write your code here
    int count, pos = 0,j;
    char c,b[2];
    for(int i = 0; a[i] != 0; i++){
        c = a[i];
        j = i;
        count = 0;
        while(a[j] == c){
            count++;
            j++;
        }
        sprintf(b,"%d",count);
        if(count > 1){
            a[pos] = a[i];
            a[++pos] = *b;
            pos++;
        }else{
            a[pos] = a[i];
            pos++;
        }
        i = j - 1;
    }
    a[pos] = 0;
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}
