/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/

#include<iostream>
#include<vector>
using namespace std;
// #include "solution.h"

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int count = 0;
    int** edges = new int*[n + 1];
    for(int i = 0; i < n + 1; i++){
        edges[i] = new int[n + 1];
        for(int j = 0; j < n + 1; j++){
           edges[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        edges[u[i]][v[i]] = 1;
        edges[v[i]][u[i]] = 1;
    }
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(j == i)
                continue;
            if(edges[i][j] == 1){
                for(int k = 1; k < n + 1; k++){
                    if(k == i || k == j)
                        continue;
                    if(edges[k][j] == 1 && edges[k][i] == 1){
                        count++;
                    }
                }
            }
        }
    }
    
    return count/6;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}