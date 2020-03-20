/*
Highest Occuring Character
Send Feedback
Given a string, find and return the highest occurring character present in the given string.
If there are 2 characters in the input string with same frequency, return the character which comes first.
Note : Assume all the characters in the given string are lowercase.
Sample Input 1:

abdefgbabfba

Sample Output 1:

b

Sample Input 2:

xy

Sample Output 2:

x


*/

#include <iostream>
using namespace std;

// input - given string
char highestOccurringChar(char a[]) {
    int freq[256] = {0};
    int max = freq[a[0]];
    char max_char = a[0];
    for(int i = 0; a[i] != 0; i++){
        freq[a[i]]++;
    }
    for(int i = 0; a[i] != 0; i++){
        if(max < freq[a[i]]){
            max = freq[a[i]];
            max_char = a[i];
        }
    }
    return max_char;
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    cout << highestOccurringChar(input) << endl;
}
