/*
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
1 <= N <= 10^6
Ai contains all non-zero values
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2
*/

#include<iostream>
#include<unordered_map>
using namespace std;

void PairSum(int *input, int n) {
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        int num = -1*input[i];
        if(mp.count(num) == 1){
            int freq = mp[num];
            for(int j = 0; j < freq; j++){
                int n1 = (num < input[i]) ? num : input[i];
                int n2 = (num == n1) ? input[i] : num;
                cout<<n1<<" "<<n2<<endl;
            }
        }
        if(mp.count(input[i]) == 1){
              mp[input[i]]++;   
        }else{
             mp[input[i]] = 1;
        }
    }
}

int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}