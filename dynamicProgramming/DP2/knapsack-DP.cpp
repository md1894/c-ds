/*
Code: Knapsack (Memoization and DP)
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and ith item weigh wi and is of value vi. 
What is the maximum value V, that thief can take ?
Space complexity should be O(n).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include <iostream>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

int knapsack_(int* weights, int* values, int n, int maxWeight){
    int** ans = new int*[n + 1];
    for(int i = 0; i < n + 1; i++){
        ans[i] = new int[maxWeight + 1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= maxWeight; j++){
            if(i == 0 || j == 0){
                ans[i][j] = 0;
            }else if(weights[i - 1] > j){
                ans[i][j] = ans[i - 1][j];
            }else{
                int a = values[i - 1] + ans[i - 1][j - weights[i - 1]];
                int b = ans[i - 1][j];
                ans[i][j] = max(a, b);
            }
        }
    }
    return ans[n][maxWeight];
}

int knapsackMemoryOptimized_(int* wt, int* val, int n, int W){
    int ans[2][W + 1];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i <= n; i++)
    {
            for(int j = 1; j <= W; j++)
            {
                    if(i % 2 != 0)
                    {
                        if(wt[i] > j){
                            ans[0][j] = ans[1][j];
                        }else{
                            int a = val[i] + ans[1][j - wt[i]];
                            int b = ans[1][j];
                            ans[0][j] = max(a, b);
                        }
                    }
                    else
                    {
                        if(wt[i] > j){
                            ans[1][j] = ans[0][j];
                        }else{
                            int a = val[i] + ans[0][j - wt[i]];
                            int b = ans[0][j];
                            ans[1][j] = max(a, b);
                        }
                    }
            }
    }
    return (n % 2 == 0) ? ans[1][W] : ans[0][W];
}

int knapsack(int* wt, int* val, int n, int W){
    int mat[2][W+1]; 
    memset(mat, 0, sizeof(mat)); 
    // iterate through all items 
    int i = 0; 
    while (i < n) // one by one traverse each element 
    { 
        int j = 0; // traverse all weights j <= W 
        // if i is odd that mean till now we have odd 
        // number of elements so we store result in 1th 
        // indexed row 
        if (i%2!=0) 
        { 
            while (++j <= W) // check for each value 
            { 
                if (wt[i] <= j) // include element 
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]], 
                                    mat[0][j] ); 
                else           // exclude element 
                    mat[1][j] = mat[0][j]; 
            } 
  
        } 
        // if i is even that mean till now we have even number 
        // of elements so we store result in 0th indexed row 
        else
        { 
            while(++j <= W) 
            { 
                if (wt[i] <= j) 
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]], 
                                     mat[1][j]); 
                else
                    mat[0][j] = mat[1][j]; 
            } 
        } 
        i++; 
    } 
    // Return mat[0][W] if n is odd, else mat[1][W] 
    return (n%2 != 0)? mat[0][W] : mat[1][W];
}



int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack_(weights, values, n, maxWeight);

}