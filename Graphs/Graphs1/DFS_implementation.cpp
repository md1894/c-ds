#include<iostream>
using namespace std;

void print(int** edges, int noOfVertices, int startingVertex, bool* visited){
    cout<<startingVertex<<endl;
    visited[startingVertex] = true;
    for(int i = 0; i < noOfVertices; i++){
        if(i == startingVertex){
            continue;
        }
        if(edges[startingVertex][i] == 1){
            if(visited[i] == true){
                continue;
            }
            print(edges, noOfVertices, i, visited);
        }
    }
}


int main()
{
    int noOfVertices, noOfEdges;
    cin>>noOfVertices;
    cin>>noOfEdges;
    int** edges = new int*[noOfVertices];
    for(int i = 0; i < noOfVertices; i++){
        edges[i] = new int[noOfVertices];
        for(int j = 0; j < noOfVertices; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < noOfEdges; i++){
        int first, second;
        cin>>first;
        cin>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    bool* visited = new bool[noOfVertices];
    for(int i = 0; i < noOfVertices; i++){
        visited[i] = false;
    }
    print(edges, noOfVertices, 0, visited);
    return 0;
}