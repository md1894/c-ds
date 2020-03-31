/*
Coin Tower
Send Feedback
Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?
Input Format :
Contains three value N,X,Y as mentioned in the problem statement
Output Format :
A string containing the name of the winner like “Whis” or “Beerus” (without quotes)
Constraints:
1<=N<=10^6
2<=X<=Y<=50
Sample Input :
 4 2 3
Sample Output :
 Whis
*/


#include<iostream>
#include<string>
using namespace std;
// #include "solution.h"

int solve_(int n, int x, int y){
    if(n == 1 || n == x || n == y)
        return 1;
    
    int s1 = solve_(n - 1, x, y) ^ 1;
    int s2 = solve_(n - x, x, y) ^ 1;
    int s3 = solve_(n - y, x, y) ^ 1;
    return max(s1, max(s2, s3));
}

int solve_DP(int n, int x, int y){
    int ans[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    ans[x] = 1;
    ans[y] = 1;
    for(int i = 2; i < n + 1; i++){
        int s1 = ans[i - 1] ^ 1;
        int s2 = 0;
        int s3 = 0;
        if(i >= x){
            s2 = ans[i - x] ^ 1;
        }
        if(i >= y){
            s3 = ans[i - y] ^ 1;
        }
        ans[i] = max(s1, max(s2, s3));
    }
    return ans[n];
}

string solve(int n, int x, int y)
{
	if(solve_DP(n,x,y)){
        return "Beerus";
    }else{
        return "Whis";
    }
}


int n,x,y;
int main()
{
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
}