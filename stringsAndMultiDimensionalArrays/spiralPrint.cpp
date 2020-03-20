/*
Spiral Print
Send Feedback
Given an N*M 2D array, print it in spiral form. That is, first you need to print the 1st row, then last column, then last row and then first column and so on.
Print every element only once.
Input format :

Line 1 : N and M, No. of rows & No. of columns (separated by space) followed by N*M  elements in row wise fashion.

Sample Input :

 4 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Sample Output :

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 


*/

#include <iostream>
using namespace std;


void spiralPrint(int a[][1000], int m, int n){
    int count = 0,i,j,cs,ce,rs,re;
    re = m - 1;
    rs = 0;
    ce = n - 1;
    cs = 0;
    while(count < (m*n)){
        i = rs;
        j = cs;
        while(j<= ce && count < m*n){
            cout<<a[i][j]<<" ";
            count++;
            j++;
        }
        rs++;
        i = rs;
        j = ce;
        while(i<= re && count < m*n){
            cout<<a[i][j]<<" ";
            count++;
            i++;
        }
        ce--;
        j = ce;
        i = re;
        while(j>=cs && count < m*n){
            cout<<a[i][j]<<" ";
            count++;
            j--;
        }
        re--;
        i = re;
        j = cs;
        while(i>=rs && count < m*n){
            cout<<a[i][j]<<" ";
            count++;
            i--;
        }
        cs++;
    }
}



int main() {
    int input[1500][1000];
    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    spiralPrint(input, row, col);
}
