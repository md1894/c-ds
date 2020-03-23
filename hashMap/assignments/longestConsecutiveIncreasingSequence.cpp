/*
Longest consecutive Sequence
Send Feedback
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 50000
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16

repeated value test case

7
5 1 2 3 6 7 5
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <utility>
using namespace std;

typedef pair<int,bool> info;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	 //Your Code goes here
    unordered_map<int, info> map_;
    vector<int> vector_;
    int lengthOfMaxSubSequence = -1, mainStart, currentLength, currentElement, currentStart, startIndex = INT_MAX;
    int currentStartIndex;
    for(int i = 0; i < n; i++){
      if(map_.count(arr[i])==0){
          map_[arr[i]].second = true;
          map_[arr[i]].first = i;
        }
      // map_[arr[i]].second = true; // what if the elements in input are repeated
      // map_[arr[i]].first = i;
    }
    for(int i = 0; i < n; i++){
        if(map_[arr[i]].second){
            map_[arr[i]].second = false;
            currentLength = 1;
            currentStart = arr[i];
            currentElement = currentStart + 1;
            while(map_.count(currentElement) == 1){
                if(map_[currentElement].second == false){
                    break;
                }
                currentLength++;
                map_[currentElement].second = false;
                currentElement++;
            }
            currentElement = currentStart - 1;
            while(map_.count(currentElement) == 1){
                if(map_[currentElement].second == false){
                    break;
                }
                currentLength++;
                map_[currentElement].second = false;
                currentStart = currentElement;
                currentElement--;
            }
            currentStartIndex = map_[currentStart].first;
            if(currentLength >= lengthOfMaxSubSequence ){
                bool isValid = false;
                if(currentLength == lengthOfMaxSubSequence){
                    if(startIndex > currentStartIndex){
                        isValid = true;
                    }
                }else{
                    isValid = true;
                }
                if(isValid){
                  lengthOfMaxSubSequence = currentLength;
                  mainStart = currentStart;
                  startIndex = currentStartIndex;
                }
            }
        }
    }
    for(int i = 0; i < lengthOfMaxSubSequence; i++){
      vector_.push_back(mainStart + i);
    }
    return vector_;
}

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete [] arr;
}
