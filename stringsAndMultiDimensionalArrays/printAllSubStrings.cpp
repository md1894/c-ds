/*
Print All Substrings
Send Feedback
Given a String S of length n, print all its substrings.
Substring of a String S is a part of S (of any length from 1 to n), which contains all consecutive characters from S.
Input Format :

String S

Output Format :

 All Substrings of S, one in each line.

Note : The order in which you print substrings doesn't matter.
Sample Input 1 :

xyz

Sample Output 1 :

x
xy
xyz
y
yz
z


*/

#include<iostream>
using namespace std;


void printSubstrings(char str[]){
    int i,j,count;
    for(i=0;str[i]!=0;i++){
        count = i;
        while(str[count]!=0){
            for(j=i;j<=count;j++){
                cout<<str[j];
            }
            cout<<endl;
            count++;
        }
    }
}


int main(){

  char str[10000];
  cin.getline(str,10000);

  printSubstrings(str);
}
