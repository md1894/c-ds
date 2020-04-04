/*
Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3
*/

#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
// #include "solution.h"
char cake[NMAX][NMAX];

#include <climits>



int solve(char cake[NMAX][NMAX], int n, int i, int j, bool** visited){
    visited[i][j] = true;
    int count = 0;
    //check upside
    if(i-1 >=0 && visited[i-1][j] == false && '1' == cake[i-1][j]){
        count += solve(cake, n, i-1, j, visited);
    }
    
    //check downside
    if(i+1 < n && visited[i+1][j] == false && cake[i+1][j] == '1'){
        count += solve(cake, n, i+1, j, visited);
    }
    
    //check right
    if(j+1 < n && visited[i][j+1] == false && cake[i][j+1] == '1'){
        count += solve(cake, n, i, j+1, visited);
    }
    
    //check left
    if(j-1 >= 0 && visited[i][j-1] == false && cake[i][j-1] == '1'){
        count += solve(cake, n, i, j-1, visited);
    }
    
    return count + 1;
}


int solve(int n,char cake[NMAX][NMAX])
{
    bool** visited = new bool*[n];
    int current, max_count = 0;
    for(int i = 0; i < n; i++){
        visited[i] = new bool[n];
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == '1' && visited[i][j] == false){
                current = solve(cake, n, i, j, visited);
                if(current > max_count){
                    max_count = current;
                }
            }
        }
    }
    return max_count;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}