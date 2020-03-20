/*
 Sort 0 1
Send Feedback
You are given an integer array A that contains only integers 0 and 1. Write a function to sort this array. Find a solution which scans the array only once. Don't use extra array.
You need to change in the given array itself. So no need to return or print anything.
Input format :

Line 1 : Integer N (Array Size)
Line 2 : Array elements (separated by space)

Output format :

Sorted array elements

Constraints :
1 <= N <= 10^6
Sample Input :

7
0 1 1 0 1 0 1

Sample Output :

0 0 0 1 1 1 1


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

void SortZeroesAndOne(int arr[], int n){
    int pos=0,i;
    for(i=0;i<n;i++){
        if(arr[i] == 0){
            swap(arr,i,pos);
            pos++;
        }
    }
    
}

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	SortZeroesAndOne(input,size);
		
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";	
	return 0;
}
