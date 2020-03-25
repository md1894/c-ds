/*
Code : Min Cost Path
Send Feedback
Given an integer matrix of size m*n, you need to find out 
the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)
Output Format :
Minimum cost
Constraints :
1 <= m, n <= 20
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
*/

#include <iostream>
#include <vector>
#include <climits>
// #include <cmath>
using namespace std;

// BRUTE FORCE SOLUTION
// int minCostPath(int** input, int m, int n, int i, int j){
//     if(i == m - 1 && j == n - 1){
//         return input[i][j];
//     }
//     if(i > m - 1 || j > n - 1){
//         return INT_MAX;
//     }
//     int a = minCostPath(input, m, n, i, j + 1);
//     int b = minCostPath(input, m, n, i + 1, j + 1);
//     int c = minCostPath(input, m, n, i + 1, j);

//     int min_ = min(a, min(b, c));
//     int ans = min_ + input[i][j];
//     return ans;
// }

// // MEMOIZTION APPROACH
// int minCostPath_mem(int **input, int m, int n, int i, int j, int** output){
//     if(i == m - 1 && j == n - 1){
//         return input[i][j];
//     }
//     if(i > m - 1 || j > n - 1){
//         return INT_MAX;
//     }

//     if(output[i][j] != -1){
//         return output[i][j];
//     }

//     int a = minCostPath_mem(input, m, n, i, j + 1, output);
//     if(a < INT_MAX){
//         output[i][j + 1] = a;
//     }
//     int b = minCostPath_mem(input, m, n, i + 1, j + 1, output);
//     if(b < INT_MAX){
//         output[i + 1][j + 1] = b;
//     }
//     int c = minCostPath_mem(input, m, n, i + 1, j, output);
//     if(c < INT_MAX){
//         output[i + 1][j] = c;
//     }

//     int min_ = min(a, min(b, c));
//     int ans = min_ + input[i][j];

//     output[i][j] = ans;
//     return ans;

// }


// DYNAMIC PROGRAMMING APPROACH
int minCostPath_DP(int **input, int m, int n){
     int** output = new int*[m];
     for(int i = 0; i < m; i++){
         output[i] = new int[n];
     }

     // filled the corner most element
     output[m - 1][n - 1] = input[m - 1][n - 1];

     // filled the last row
     for(int i = n - 2; i >= 0; i--){
         output[m - 1][i] = output[m - 1][i + 1] + input[m - 1][i];
     }

     // filled the last column
     for(int i = m - 2; i >= 0; i--){
         output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
     }

     // filling the remaining cells
     for(int i = m - 2; i >= 0; i--){
         for(int j = n - 2; j >= 0; j--){
             output[i][j] = input[i][j] + min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j]));
         }
     }
     return output[0][0];
}

int minCostPath(int **input, int m, int n) {
    // BRUTE FORCE SOLUTION
    // return minCostPath(input, m, n, 0, 0);

    // MEMOIZATION APPROACH
    // int** output = new int*[m];
    // for(int i = 0; i < m; i++){
    //     output[i] = new int[n];
    //     for(int j = 0; j < n; j++){
    //         output[i][j] = -1;
    //     }
    // }
    // return minCostPath_mem(input, m, n, 0, 0, output);

    //DP APPROACH
    return minCostPath_DP(input, m, n);    
}

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}