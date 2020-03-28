/*
Matrix Chain Multiplication
Send Feedback
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format :
Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[] 
Output Format :
Line 1 : Minimum number of multiplication needed
Constraints :
1 <= n <= 100
Sample Input 1 :
3
10 15 20 25
Sample Output :
8000
Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000
*/
#include<iostream>
using namespace std;
// #include "Solution.h"

#include <climits>

int mcm(int* p, int s, int e){
    if(s == e)
        return 0;
    
    int min = INT_MAX;
    int k;
    
    for(k = s; k < e; k++)
    {
        int curr = mcm(p, s, k) + mcm(p, k + 1, e) + (p[s - 1]*p[k]*p[e]);
        if(curr < min)
        {
            min = curr;
        }
    }
    return min;
}

int mcm_memoization(int* p, int s, int e, int** ans){
    if(s == e){
        ans[s][e] = 0;
        return 0;
    }
    
    if(ans[s][e] != -1)
        return ans[s][e];
    
    int min = INT_MAX;
    for(int i = s; i < e; i++){
        int curr = mcm_memoization(p,s,i,ans) + mcm_memoization(p,i+1,e,ans) + p[s-1]*p[i]*p[e];
        if(curr < min){
            min = curr;
        }
    }
    ans[s][e] = min;
    return min;
}

int mcm_memoization(int* p, int n){
    int** ans = new int*[n];
    for(int i = 0; i < n ;i++){
        ans[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans[i][j] = -1;
    
    return mcm_memoization(p,1,n - 1,ans);
}

int mcm_DP(int* p, int e){
    int ans[e][e];
    
    for(int i = 0; i < e; i++){
        ans[i][i] = 0;
    }
    
    for(int L = 2; L < e; L++){
        for(int i = 1; i <= e - L; i++){
            int j = i + L - 1;
            ans[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k+1][j]+ (p[i - 1]*p[k]*p[j]));
            }
        }
    }
    return ans[1][e - 1];
}

int mcm(int* p, int n){
    // return mcm(p, 1, n);
    // return mcm_memoization(p,n);
    return mcm_DP(p, n);
}


int main(){

  int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i < n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n);

}


