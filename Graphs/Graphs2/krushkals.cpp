/*
Code : Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
  public:
    int source;
    int dest;
    int weight;
};

bool comparator_(Edge e1, Edge e2){
  return e1.weight < e2.weight;
}

int findParent(int vertex, int* parent){
  if(vertex == parent[vertex]){
    return vertex;
  }else{
    return findParent(parent[vertex], parent);
  }
}

void kruskals(Edge* input, int n, int E){
  sort(input, input + E, comparator_);
  Edge* output = new Edge[n - 1];
  int* parent = new int[n];
  for(int i = 0; i < n; i++){
    parent[i] = i;
  }
  int count = 0;
  int i = 0;
  while(count != n-1){
    Edge currentEdge = input[i];
    int sourceParent = findParent(currentEdge.source, parent);
    int destParent = findParent(currentEdge.dest, parent);
    if(sourceParent != destParent){
      output[count] = currentEdge;
      parent[sourceParent] = destParent;
      count++;
    }
    i++;
  }
  for(int i = 0; i < n - 1; i++){
    if(output[i].source < output[i].dest){
      cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }else{
      cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
  }
}

int main()
{
  int n, E;
  cin >> n >> E;
  Edge* input = new Edge[E];
  for(int i = 0; i < E; i++){
    int s, d, w;
    cin >> s >> d >> w;
    input[i].source = s;
    input[i].dest = d;
    input[i].weight = w;
  }
  kruskals(input, n, E);
  return 0;
}