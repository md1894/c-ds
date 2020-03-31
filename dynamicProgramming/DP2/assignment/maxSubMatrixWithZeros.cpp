/*
Maximum Square Matrix With All Zeros
Send Feedback
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/

#include<iostream>
// #include"solution.h"
using namespace std;


using namespace std;
#include <climits>

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int ans[row][col];
    for(int i = 0; i < row; i++){
        ans[i][0] = arr[i][0];
    }
    for(int i = 0; i < col; i++){
        ans[0][i] = arr[0][i];
    }
    int ans_ = ans[0][0];
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
                int a = ans[i - 1][j - 1];
                int b = ans[i - 1][j];
                int c = ans[i][j - 1];
            if(arr[i][j] == 0){
                ans[i][j] = min(a,min(b,c)) + 1;      
            }else{
                ans[i][j] = 0;
            }
            if(ans_ < ans[i][j]){
                ans_ = ans[i][j];
            }
        }
    }
    return ans_;
//     int i,j;  
//     int S[R][C];  
//     int max_of_s, max_i, max_j;  
      
//     /* Set first column of S[][]*/
//     for(i = 0; i < R; i++)  
//         S[i][0] = M[i][0];  
      
//     /* Set first row of S[][]*/
//     for(j = 0; j < C; j++)  
//         S[0][j] = M[0][j];  
          
//     /* Construct other entries of S[][]*/
//      max_of_s = S[0][0];
//     for(i = 1; i < R; i++)  
//     {  
//         for(j = 1; j < C; j++)  
//         {  
//             if(M[i][j] == 0)  
//                 S[i][j] = min(S[i][j-1],min( S[i-1][j],  
//                                 S[i-1][j-1])) + 1;  
//             else
//                 S[i][j] = 0;
            
//             if(max_of_s < S[i][j]){
//                 max_of_s = S[i][j];
//             }
//         }  
//     } 
    
//     return max_of_s;
    
    
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}