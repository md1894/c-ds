/*
Code : Min Steps to 1
Send Feedback
Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.
1.) Subtract 1 from it. (n= n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).  
Just write brute-force recursive solution for this.
Input format :
Line 1 : A single integer i.e. n
Output format :
Line 1 : Single integer i.e number of steps
Constraints :
1 <= n <= 500
Sample Input 1 :
4
Sample Output 1 :
2 
Sample Output 1 Explanation :
For n = 4
Step 1 : n = 4/2 = 2
Step 2 : n = 2/2 = 1
Sample Input 2 :
7
Sample Output 2 :
3
Sample Output 2 Explanation :
For n = 7
Step 1 : n = 7 ­ - 1 = 6
Step 2 : n = 6 / 3 = 2
Step 3 : n = 2 / 2 = 1
*/

#include<iostream>
#include<climits>
using namespace std;

// BRUTE FORCE VERSION
// int countStepsTo1(int n){
//     if(n == 1)
//         return 0;
    
//     int n1 = INT_MAX, n2 = INT_MAX, n3 = INT_MAX;
//     n1 = 1 + countStepsTo1(n - 1);
//     if(n % 2 == 0){
//         n2 = 1 + countStepsTo1(n/2);
//     }
//     if(n % 3 == 0){
//         n3 = 1 + countStepsTo1(n/3);
//     }
//     int min = (n1 < n2 && n1 < n3) ? n1 : (n2 < n3) ? n2 : n3;
//     return min;
// }


// MEMOIZATION APPROACH
// int countStepsTo1_(int n, int* ans){
//     if(n == 1){
//         return 0;
//     }

//     if(ans[n] != -1)
//         return ans[n];

//     int n1 = INT_MAX, n2 = INT_MAX, n3 = INT_MAX;
//     if(n % 3 == 0){
//             n3 = 1 + countStepsTo1_(n/3, ans);
//     }

//     if(n % 2 == 0){
//             n2 = 1 + countStepsTo1_(n/2, ans);
//     }

//     n1 = 1 + countStepsTo1_(n - 1, ans);
    
//     int min = (n1 < n2 && n1 < n3) ? n1 : (n2 < n3) ? n2 : n3;
//     ans[n] = min;
//     return min;
// }

// int countStepsTo1(int n){
//     int* ans = new int[n + 1];
//     for(int i = 0; i < n + 1; i++){
//         ans[i] = -1;
//     }
//     return countStepsTo1_(n,ans); // helper function for memoization approach
// }

// DYNAMIC PROGRAMMING APPROACH
int countSteps_DP(int n, int* ans){
    if(n <= 1){
        return 0;
    }
    if(n == 2 || n == 3){
        return 1;
    }
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    int n1, n2, n3;
    for(int i = 4; i < n + 1; i++){
        n1 = ans[i - 1];
        if(ans[i - 1] != INT_MAX){
            n1++;
        }
        if(i % 2 == 0){
            n2 = 1 + ans[i/2];
        }else{
            n2 = INT_MAX;
        }
        if(i % 3 == 0){
            n3 = 1 + ans[i/3];
        }else{
            n3 = INT_MAX;
        }
        int min = (n1 < n2 && n1 < n3) ? n1 : (n2 < n3) ? n2 : n3;
        ans[i] = min;
    }
    return ans[n];
}

int countStepsTo1(int n){
    int* ans = new int[n + 1];
    for(int i = 0; i < n + 1; i++){
        ans[i] = INT_MAX;
    }
    return countSteps_DP(n,ans);
}

int main(){

  int n;
  cin  >> n;
  cout << countStepsTo1(n) << endl;
  return 0;
}




