/*
Code : Staircase using Dp
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/

#include<iostream>
using namespace std;

long staircase_DP(int n, long* ans){
    if(n <= 1){
        return n;
    }
    long n1, n2, n3 = 0;
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i < n + 1; i++){
        n1 = ans[i - 1];
        n2 = ans[i - 2];
        if(i - 3 >= 0){
            n3 = ans[i - 3];
        }
        long total = n1 + n2 + n3;
        ans[i] = total;
    }
    return ans[n];
}

long staircase(int n){
    long* ans = new long[n + 1];
    for(int i = 0; i < n + 1; i++){
        ans[i] = 0;
    }
    return staircase_DP(n, ans);
}


int main(){

  int n; 
  cin >> n ;
  cout << staircase(n) << endl;

}


