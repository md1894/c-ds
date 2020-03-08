#include<iostream>
using namespace std;


void insertion_sort(int a[], int n){
    /*
     * array is divided into two halves
     * one is 'sorted' and other is 'unsorted'
     * target element --> one greater than sorted array
     * pick target --> a[i], scan through all sorted array
     * accordingly shift sorted elements
     * make place for the target element 
     */
    for(int i = 1; i < n; i++)
    {
        int target = a[i];
        int j = i - 1;
        while(j > -1 && a[j] > target)
	{
            /*
	     * j + 1 --> already captured in target variable
	     */
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = target;
    }
}

int main(){
    int a[] = {8,3,9,1,2}, n = 5;
    insertion_sort(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
