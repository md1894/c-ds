/*
Longest subset zero sum
Send Feedback
Given an array consisting of positive and negative integers, find the length of the longest continuous subset whose sum is zero.
NOTE: You have to return the length of longest subset .
Input Format :
Line 1 : Contains an integer N i.e. size of array

Line 2 : Contains N elements of the array, separated by spaces
Output Format
 Line 1 : Length of longest continuous subset 
Sample Input :
10 
95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output :
5
*/

#include <iostream>
#include <unordered_map>
using namespace std;



int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  unordered_map<int,int> map_;
  int length = 0, lMax = 0, sum = 0;
  bool add;
  for(int i = 0; i < size; i++){
	    sum += arr[i];
	    add = true;
	    if(sum == 0 && map_.count(0) == 0){
		      add = false;
		      length = i + 1;
		      if(length > lMax){
				lMax = length;
		      }
		      map_[sum] = i;
	    }
	    if(map_.count(sum) == 1 && add){
		      length = i - map_[sum];
		      add = false;
		      if(length > lMax){
			lMax = length;
		      }
	    }
	    if(add){
		map_[sum] = i;
	    }
  }
  return lMax;
}


int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}
