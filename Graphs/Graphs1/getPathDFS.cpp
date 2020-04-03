/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/


#include <iostream>
#include <vector>
using namespace std;

vector<int>* getPath(int** edges, int V, int a, int b, bool* visited){
    if(a == b){
        vector<int>* v = new vector<int>();
        return v;
    }else{
        visited[a] = true;
        for(int i = 0; i < V; i++){
            if(i == a)
                continue;
            
            if(edges[i][a] == 1 && visited[i] == false){
                vector<int>* v = getPath(edges, V, i, b, visited);
                if(v != NULL){
                    v->push_back(i);
                    return v;
                }
            }
        }
    }
    return NULL;
}


vector<int>* getPath(int** edges, int V, int a, int b){
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    
    vector<int>* v = getPath(edges, V, a, b, visited);
    if(v != NULL){
        v->push_back(a);
        return v;
    }
    return NULL;
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
        for(int j = 0; j < V; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < E; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cin >> tempX >> tempY;
    vector<int>* v = getPath(edges, V, tempX, tempY);
    if(v != NULL){
        for(int i = 0; i < v->size(); i++){
            cout<<(*v)[i]<<" ";
        }
    }
    delete v;
    return 0;
}
