/*Pairs with difference K
Send Feedback
You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Best solution takes O(n) time. And take difference as absolute.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)
Constraints :
1 <= n <= 5000
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2 5
1 4
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4
*/

#include<iostream>
#include<utility>
#include<unordered_map>
using namespace std;

int fact(int n){
	if(n==0 || n == 1)
		return 1;
	else
		return n*fact(n-1);
}

void pVal(int n, int n1, int n2){
	int small = (n1 > n2) ? n2 : n1;
	int big = (n1 == small) ? n2 : n1;
	for(int i = 0; i < n; i++){
		cout<<small<<" "<<big<<endl;
	}
}

void init(unordered_map<int,int>* map_, int* input, int n){
	for(int i = 0; i < n; i++){
		if(map_->count(input[i]) == 1){
			(*map_)[input[i]]++;
		}else{
			(*map_)[input[i]] = 1;
		}
	}
}

void type1(int* input, int k, int n){
	unordered_map<int,int> map_;
	init(&map_, input, n);
	for(int i = 0; i < n; i++){
		if(map_.count(input[i]) == 1){
			int freq = map_[input[i]];
			if(freq > 1){
				int n = fact(freq - 1);
				pVal(n, input[i], input[i]);
			}
			map_.erase(input[i]);
		}
	}
}

void type2(int* input, int k, int n){
	unordered_map<int,int> map_;
	init(&map_, input, n);
	for(int i = 0; i < n; i++){
		int p = input[i] + k;
		if(map_.count(p) == 1){
			int f1 = map_[input[i]];
			int f2 = map_[p];
			int f = f1*f2;
			pVal(f,p,input[i]);
		}
		p = input[i] - k;
		if(map_.count(p) == 1){
			int f1 = map_[input[i]];
			int f2 = map_[p];
			int f = f1*f2;
			pVal(f,p,input[i]);
		}
		map_.erase(input[i]);
	}
}

void printPairs(int *input, int n, int k) {
	// Write your code here
	if(k == 0)
		type1(input, k, n);
	else
		type2(input, k, n);
	
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
