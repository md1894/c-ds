/*
Binary Search (Recursive)
Send Feedback
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
*/

#include <iostream>
// #include "solution.h"
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched

int bsearch(int a[], int x, int s, int e){
    if(s<e){
        int mid = (s+e)/2;
        if(a[mid] == x){
            return mid;
        }else if(a[mid] < x){
            return bsearch(a,x,mid+1,e);
        }else{
            return bsearch(a,x,s,mid-1);
        }
    }
    return -1;
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
