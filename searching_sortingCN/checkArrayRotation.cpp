/*
Check array rotation
Send Feedback
Given an integer array, which is sorted (in increasing order) and has been rotated by some number k in clockwise direction. Find and return the k.
Input format :

Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)

Output Format :

Integer k

Constraints :
1 <= n <= 1000
Sample Input 1:

6
5 6 1 2 3 4

Sample Output 1:

2

Sample Input 2:

5
3 6 8 9 10

Sample Output 2:

0


*/


#include <iostream>
using namespace std;


// arr - input array
// n - size of array

int FindSortedArrayRotation(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i+1]<arr[i]){
            count = i + 1;
            break;
        }
    }
    return count;

}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSortedArrayRotation(input,size);
	
	return 0;

}
