/*
Rotate array
Send Feedback
Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Input format :

Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer d

Output Format :

Updated array elements (separated by space)

Constraints :
1 <= N <= 1000
1 <= d <= N
Sample Input :

7
1 2 3 4 5 6 7
2

Sample Output :

3 4 5 6 7 1 2


*/

#include <iostream>
using namespace std;


// arr - input array
// size - size of array
// d - array to be rotated by d elements

	

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
    
}

void Rotate(int arr[],int element,int size){
    for(int i = 0 ; i < gcd(size,element) ; i++){
        int temp = arr[i];
        int j = i;
        while(1){
            int k = j + element;
            if(k>=size)
                k = k - size;

            if(k==i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}


int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}
