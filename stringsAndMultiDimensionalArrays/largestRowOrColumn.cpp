/*
Largest Row or Column
Send Feedback
Given an NxM 2D array, you need to find out which row or column has largest sum (sum of its elements) overall amongst all rows and columns.
Input Format :

 Line 1 : 2 integers N and M respectively, separated by space 
 Line 2: Single line having N*M elements entered in row wise manner, each separated by space.

Output Format :

 If row sum is maximum then - "row" row_num max_sum
 If column sum is maximum then - "column" col_num max_sum

Note : If there are more than one rows/columns with maximum sum consider the row/column that comes first. And if ith row and jth column has same sum (which is largest), consider the ith row as answer.
Sample Input 1 :

2 2 
1 1 1 1

Sample Output 1 :

row 0 2

Sample Input 2 :

3 3
3 6 9 1 4 7 2 8 9

Sample Output 2 :

column 2 25


*/


#include<iostream>
using namespace std;



void findLargest(int arr[][1000], int row, int col){
    int sum,row_n,col_n,max = 0;
    char m = 'r';
    for(int i = 0;i < row;i++){
        sum = 0;
        for(int j = 0; j < col; j++){
            sum = sum + arr[i][j];
        }
        if(sum > max){
            max = sum;
            row_n = i;
            m = 'r';
        }
    }
    
    for(int i = 0;i < col;i++){
        sum = 0;
        for(int j = 0; j < row; j++){
            sum = sum + arr[j][i];
        }
        if(sum > max){
            max = sum;
            col_n = i;
            m = 'c';
        }
    }
    if(m == 'r'){
        cout<<"row"<<" "<<row_n<<" "<<max;
    }else{
        cout<<"column"<<" "<<col_n<<" "<<max;
    }
}


int main() {
    int row, col;
    cin >> row >> col;

    int input[1000][1000]; 
    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    findLargest(input, row, col);
}
