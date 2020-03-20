/*
Sum of two arrays
Send Feedback
Two random integer arrays are given A1 and A2, in which numbers from 0 to 9 are present at every index (i.e. single digit integer is present at every index of both given arrays).
You need to find sum of both the input arrays (like we add two integers) and put the result in another array i.e. output array (output arrays should also contain only single digits at every index).
The size A1 & A2 can be different.
Note : Output array size should be 1 more than the size of bigger array and place 0 at the 0th index if there is no carry. No need to print the elements of output array.
Input format :

Line 1 : Integer n1 (A1 Size)
Line 2 : A1 elements (separated by space)
Line 3 : Integer n2 (A2 Size)
Line 4 : A2 elements (separated by space)

Output Format :

Output array elements (separated by space)

Constraints :
1 <= n1, n2 <= 10^6
Sample Input 1:

3
6 2 4
3
7 5 6

Sample Output 1:

1 3 8 0

Sample Input 2:

3
8 5 2
2
1 3

Sample Output 2:

0 8 6 5


*/



#include <iostream>
using namespace std;


// input1 - first array
// size1 - size of first array
// input2 - second array
// size2 - size of second array
// output - array in which sum is to be stored

void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[]){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output. Just fill the output in given output array.
     * Taking input and printing output is handled automatically.
     */
    int carry = 0, sum = 0,k,l;
    int i,j,*a1,*a2;
    if(size1<size2){
        a1 = input2;
        i = size2-1;
        a2 = input1;
        j = size1-1;
    }else{
        a1 = input1;
        i = size1-1;
        a2 = input2;
        j = size2-1;
    }
    k = i + 1;
    for(int l = i;l >= 0; l--){
        if(j>=0){
            sum = a1[i] + a2[j] + carry;
        }else{
            sum = a1[i] + carry;
        }
        i--;
        j--;
        if(sum >= 10){
            carry = sum / 10;
            sum = sum % 10;
        }else{
            carry = 0;
        }
        output[k] = sum;
        output[--k] = carry;
    }
}


int main(){
	int size1,size2;
	cin>>size1;
	int * input1=new int[1+size1];
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

   	 cin>>size2;
	 int * input2=new int[1+size2];
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	int *output=new int[1+max(size1,size2)];
	int outsize = 1+max(size1,size2);
	sumOfTwoArrays(input1,size1,input2,size2,output);	
	
	for(int i=0;i<outsize;i++)
		cout<<output[i]<<" ";


}

