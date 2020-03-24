/*
Code : Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

#include<iostream>
using namespace std;
#include <climits>

// MEMOIZATION APPROACH
int minCount_(int n, int* ans){
     if(n <= 2)
        return n;
    
    if(ans[n] != INT_MAX)
        return ans[n];

    int curr = INT_MAX;
    int min = INT_MAX;
    int j = 1;
    for(int i = n - j; i >= 0; i = n - (j*j)){
        j++;

        if(ans[i] == INT_MAX)
            curr = 1 + minCount_(i, ans);
        else
            curr = ans[i];

        if(curr < min){
            min = curr;
        }
    }
    ans[n] = 1 + min;
    return 1 + min;
}

int minCount(int n){
   int* ans = new int[n + 1];
   for(int i = 0; i < n + 1; i++){
       ans[i] = INT_MAX;
   }
   ans[0] = 0;
   ans[1] = 1;
   return minCount_(n, ans);
}

int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
}










