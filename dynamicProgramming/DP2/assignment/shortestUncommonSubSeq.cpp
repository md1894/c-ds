/*
Shortest Subsequence
Send Feedback
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3
*/

#include<bits/stdc++.h>
using namespace std;
// #include "solution.h"


#include <climits>
#define MAX 105

int solve(string S,string T)
{
	int m = S.size(), n = T.size(); 
  
    // declaring 2D array of m + 1 rows and 
    // n + 1 columns dynamically 
    int dp[m+1][n+1]; 
  
    // T string is empty 
    for (int i = 0; i <= m; i++) 
        dp[i][0] = 1; 
  
    // S string is empty 
    for (int i = 0; i <= n; i++) 
        dp[0][i] = MAX; 
  
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            char ch = S[i-1]; 
            int k; 
            for (k = j-1; k >= 0; k--) 
                if (T[k] == ch) 
                    break; 
  
            // char not present in T 
            if (k == -1) 
                dp[i][j] = 1; 
            else
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1); 
        } 
    } 
  
    int ans = dp[m][n]; 
    if (ans >= MAX) 
        ans = 0; 
  
    return ans;
}



int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}