/*
Wave Print
Send Feedback
Given a two dimensional n*m array, print the array in a sine wave order. i.e. print the first column top to bottom, next column bottom to top and so on.
Note : Print the elements separated by space.
Input format :

n, m, array elements (separated by space)

Sample Input :

3 4 1  2  3  4 5  6  7  8 9 10 11 12

Sample Output :

1 5 9 10 6 2 3 7 11 12 8 4

 
*/

#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

void wavePrint(int input[][1000], int row, int col){
    int i,j;
    for(j = 0; j < col ; j++){
        if(j%2 == 0){
            for(int i = 0; i < row; i++){
                cout<<input[i][j]<<" ";
            }
        }else{
            for(int i = row - 1; i >= 0; i--){
                cout<<input[i][j]<<" ";
            }
        }
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
    wavePrint(input, row, col);
}
