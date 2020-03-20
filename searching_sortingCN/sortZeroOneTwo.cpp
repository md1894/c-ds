/*
Sort 0 1 2
Send Feedback
You are given an integer array containing only 0s, 1s and 2s. Write a solution to sort this array using one scan only.
You need to change in the given array itself. So no need to return or print anything.
Input format :

Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)

Output Format :

Updated array elements (separated by space)

Constraints :
1 <= n <= 10^6
Sample Input:

7
0 1 2 0 2 0 1

Sample Output:

0 0 0 1 1 2 2 


*/


#include <iostream>
#include <algorithm>
using namespace std;

// arr - input array
// n - size of array


void swap(int a[],int i,int j){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void sort012(int arr[], int n)  {  
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing output is handled automatically.
     */
    int start = 0, mid = 0,end = n-1;
	int pivot = 1;

	while (mid <= end)
	{
		if (arr[mid] < pivot)		 // current element is 0
		{
			swap(arr, start, mid);
			++start, ++mid;
		}
		else if (arr[mid] > pivot)	// current element is 2
		{
			swap(arr, mid, end);
			--end;
		}
		else						 // current element is 1
		{
			++mid;
		}
	}
}





int main() {

	int size_first;

	cin>>size_first;
	int *arr_first=new int[1+size_first];	
	
	for(int i=0;i<size_first;i++)
		cin>>arr_first[i];
	
	sort012(arr_first,size_first);
		
	for(int i=0;i<size_first;i++)
		cout<<arr_first[i]<<" ";	
	return 0;
}
