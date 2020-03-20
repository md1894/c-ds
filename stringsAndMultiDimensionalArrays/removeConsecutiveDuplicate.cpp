/*
Remove Consecutive Duplicates
Send Feedback
Given a string, remove all the consecutive duplicates that are present in the given string. That means, if 'aaa' is present in the string then it should become 'a' in the output string.
Sample Input:

aabccbaa

Sample Output:

abcba
 
*/


#include <iostream>
using namespace std;

// input - given string
// You need to update in the input string itself. No need to return or print anything

void removeConsecutiveDuplicates(char a[]) {
    char last_char = a[0];
    int j = 1;
    for(int i = 1; a[i] != 0; i++){
        if(a[i] != last_char){
            a[j] = a[i];
            j++;
            last_char = a[i];
        }
    }
    a[j] = 0;
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    removeConsecutiveDuplicates(input);
    cout << input << endl;
}
