/*
Minimum Length Word
Send Feedback
Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.
Input Format :
String S
Output Format :
Minimum length word
Constraints :
1 <= Length of String S <= 10^5
Sample Input 1 :
this is test string
Sample Output 1 :
is
Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a
*/




#include<iostream>
using namespace std;
#include <climits>

void minLengthWord(char a[], char o[]){
	int start, end, len, min = INT_MAX,j;
    for(int i = 0; a[i] != 0; i++){
        j = i;
        len = 0;
        while(a[j] != 32){
            len++;
            j++;
        }
        if(min > len){
            min = len;
            start = i;
            end = j- 1;
        }
        if(a[j] == 0)
            break;
        else
            i = j;
    }
    int i;
    for(j = start, i = 0; j <= end; j++,i++){
        o[i] = a[j];
    }
    o[i] = 0;
}



int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
