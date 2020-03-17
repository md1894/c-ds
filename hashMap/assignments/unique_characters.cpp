/*
Extract Unique characters
Send Feedback
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
1 <= Length of S <= 50000
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include<iostream>
using namespace std;
#include <unordered_map>
#include <string.h>

char* uniqueChar(char *str){
    // Write your code here
    unordered_map<char, int> mp;
    int len = strlen(str);
    char* newArr = new char[len];
    int j = 0;
    for(int i = 0; str[i] != 0; i++){
        if(mp.count(str[i]) == 0){
            mp[str[i]] = 0;
            newArr[j] = str[i];
            j++;
        }
    }
    newArr[j] = '\0';
    return newArr;
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}