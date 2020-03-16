/*
Code : Print Intersection
Send Feedback
Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
Note : Order of elements are not important
Input format :
Line 1 : Integer N, Array 1 Size
Line 2 : Array 1 elements (separated by space)
Line 3 : Integer M, Array 2 Size
Line 4 : Array 2 elements (separated by space)
Output format :
Print intersection elements in different lines
Constraints :
1 <= M, N <= 10^6
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 
2
1
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

void intersection(int arr1[], int arr2[], int n1, int n2) 
{
    unordered_map<int,int> mp;
    int* largerArray = (n1 > n2) ? arr1 : arr2;
    int largeArraySize = (n1 > n2) ? n1 : n2;
    int* smallerArray = (largerArray == arr1) ? arr2 : arr1;
    int smallerArraySize = (largeArraySize == n1) ? n2 : n1;
    
    for(int i = 0; i < largeArraySize; i++){
        
        if(mp.count(largerArray[i]) == 1){
            mp[largerArray[i]]++; 
        }else{
            mp[largerArray[i]] = 0;
        }
    }
    
    for(int i = 0; i < smallerArraySize; i++){

        if(mp.count(smallerArray[i]) == 1){

            if(mp[smallerArray[i]] >=0){

                cout<<smallerArray[i]<<endl;
                mp[smallerArray[i]]--;
            }
        }
    }
}

int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}