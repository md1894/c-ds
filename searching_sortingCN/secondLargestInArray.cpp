/*
Second Largest in array
Send Feedback
Given a random integer array of size n, find and return the second largest element present in the array.
If n <= 1 or all elements are same in the array, return -2147483648 i.e. -2^31.
Input format :

Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)

Output Format :

Second largest element

Constraints :
1 <= N <= 10^6
Sample Input 1:

7
2 13 4 1 3 6 28

Sample Output 1:

13

Sample Input 2:

5
9 3 6 2 9

Sample Output 2:

6

Sample Input 3:

2
6 6

Sample Output 3:

-2147483648


*/

#include <iostream>
using namespace std;


// arr - input array
// n - size of array

#include<climits>

int FindSecondLargest(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int largest = arr[0] , sec_largest = INT_MIN,temp;
    if(n>1){
        for(int i = 1;i<n;i++){
            if(arr[i]>sec_largest && arr[i]!= largest){
                if(arr[i]> largest){
                    sec_largest = largest;
                    largest = arr[i];
                }else{
                    sec_largest = arr[i];
                }
            }
        }   
    }
    return sec_largest;
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSecondLargest(input,size);
	
	return 0;

}

