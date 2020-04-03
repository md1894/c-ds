/*
Code : BFS Traversal
Send Feedback
Given an undirected and connected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include <iostream>
#include <queue>
using namespace std;

void print(int** edges, int V, int sv, bool* visited){
    queue<int> q;
    if(visited[sv] == false){
        q.push(sv);
        visited[sv] = true;   
    }
    while(!q.empty()){
        sv = q.front();
        cout<<sv<<" ";
        q.pop();
        for(int i = 0; i < V; i++){
            if(i == sv)
                continue;
            
            if(edges[sv][i] == 1){
                if(visited[i] == true){
                    continue;
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
        for(int j = 0; j < V; j++){
            edges[i][j] = 0;
        }
    }
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    for(int i = 0; i < E; i++){
        int first, second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    for(int i = 0; i < V; i++){
        print(edges, V, i, visited);
    }
    return 0;
}
