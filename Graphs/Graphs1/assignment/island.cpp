/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/

#include<vector>
#include<iostream>
using namespace std;

void solve(int** edges, int V, int sv, bool* visited){
    visited[sv] = true;
    for(int i = 1; i < V; i++){
        if(i == sv)
            continue;
        
        if(visited[i] != true && edges[sv][i] == 1){
            solve(edges, V, i, visited);
        }
    }
}

int solve(int n,int m,vector<int> u,vector<int> v)
{
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
    bool* visited = new bool[n];
    for(int i = 0; i < n + 1; i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i = 1; i < n + 1; i++){
        if(visited[i] != true){
            solve(edges, n + 1, i, visited);
            count++;
        }
    }
    return count;
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



