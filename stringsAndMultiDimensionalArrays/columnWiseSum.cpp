/*
Column Wise Sum
Send Feedback
Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.
Input Format :

Line 1 : Two integers M and N (separated by space)
Next M lines : ith row elements (separated by space)

Output Format :

Sum of every ith column elements (separated by space)

Constraints :
1 <= M, N <= 10^3
Sample Input :

4 2
1 2
3 4
5 6
7 8

Sample Output :

16 20

 
*/


#include<iostream>
using namespace std;


int main(){
    int a[1000][1000],col,row,count;
    cin>>row;
    cin>>col;
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i < col;i++){
        count = 0;
        for(int j = 0; j < row;j++){
            count = count + a[j][i];
        }
        cout<<count<<" ";
    }
}


