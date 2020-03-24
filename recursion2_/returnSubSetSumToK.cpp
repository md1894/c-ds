/*
Return subsets sum to K
Send Feedback
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
*/

#include <iostream>
// #include "solution.h"
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
void shiftAndAdd(int op[], int size, int el){
    int i;
    for(i = size; i > 0; i--){
        op[i] = op[i-1];
    }
    op[i] = el;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n == 0){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }else{
            return 0;
        }
    }
    int o1[500][50];
    int o2[500][50];
    int s1 = subsetSumToK(input+1, n-1, o1, k-input[0]);
    int s2 = subsetSumToK(input+1, n-1, o2, k);
    for(int i = 0; i < s1; i++){
        o1[i][0]++;
        shiftAndAdd(o1[i] + 1, o1[i][0], input[0]);
    }
    int j;
    for(j=0; j < s1; j++){
        output[j][0] = o1[j][0];
        for(int k = 1; k <= output[j][0]; k++){
            output[j][k] = o1[j][k];
        }
    }
    for(int l = j; l < j + s2; l++){
        output[l][0] = o2[l - j][0];
        for(int k = 1; k <= output[l][0]; k++){
            output[l][k] = o2[l-j][k];
        }
    }
    return s1+s2;
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
