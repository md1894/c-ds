/*
Does s contain t ?
Send Feedback
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
true or false
Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding
Sample Output 1 :
true
Sample Input 2 :
abcde
aeb
Sample Output 2 :
false
*/


#include<iostream>
using namespace std;

int getIndex(char a[], char ch){
	int i;
	for(i = 0; a[i] != ch; i++){
		if(a[i] == 0)
			return -1;
	}
	return i;
}

bool checksequenece(char large[] , char*small) {
	if(*small == 0)
		return true;
	else{
		int i = getIndex(large, *small);
		if(i == -1){
			return false;
		}else{
			return checksequenece(large + i, small + 1);
		}
	}
}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";
}
