/*
     A-------C----------|
     |       |          |
     |       |          |
     B-------D----E     |
             |    |     |
             |    |     |
             F----G-----|

Node are A B C D E F G
*/

#include <queue>
#include <stack>
#include <iostream>
#include <memory>
#define V 7
#define VISITED 1
#define NOT_VISITED 0
void printGraph(int graph[][V]) {
    std::cout<<"    ";
   for (int i=0; i< V; i++) 
        std::cout<<" ("<<i<<") ";
    std::cout<<std::endl;    

   for (int i=0; i<V; i++) {
    std::cout<<"("<<i<<") : ";
    for (int edges : graph[i]) {
        std::cout<<""<<edges<<"    ";
    }
    std::cout<<std::endl;   
   }
}

void addEdge(int graph[][V], int V1, int V2, int weight=1){
    // Adding Edge O(1)
    graph[V1][V2] = weight;
    graph[V2][V1] = weight;
}

void removeEdge(int graph[][V], int V1, int V2){
    // Removig edge O(1)
    graph[V1][V2] = 0;
    graph[V2][V1] = 0;
}

bool isConnected(int graph[V][V], int V1, int V2) {
    // Query O(1)
    return graph[V1][V2];
}

void bfs(int graph[][V], int startNode) {
    std::cout<<"\nBFS : ";
    std::queue<int> q;
    int isVisited[V] {NOT_VISITED};
    q.push(startNode);
    isVisited[startNode] = VISITED;
    while (!q.empty()) {
        const int v = q.front(); q.pop();
        std::cout<<v<<" ";
        for (int i=0; i<V; i++) {
            if (graph[v][i] == 1 && isVisited[i] == NOT_VISITED) {
                q.push(i);
                isVisited[i] = VISITED;
            }  
        }
    }
    std::cout<<"\n";
}

void dfs(int graph[][V], int startNode) {
    std::cout<<"\nDFS : ";
    int visited[V] {0};
    std::stack<int> s;
    s.push(startNode);
    visited[startNode] = VISITED;
    while(!s.empty()) {
        const int v = s.top(); s.pop();
        std::cout<<v<<" ";
        for (int i = 0; i< V; i++) {
            if(graph[v][i] == 1 && visited[i] == NOT_VISITED) {
                s.push(i);
                visited[i] = VISITED;
            }
        }
    }
    std::cout<<"\n";
}

int main() {
   //Adjency matrix Undirected Graph
   int graph[V][V] {0};
   addEdge(graph, 0, 1);
   addEdge(graph, 0, 2);
   addEdge(graph, 1, 3);
   addEdge(graph, 2, 3);
   addEdge(graph, 2, 6);
   addEdge(graph, 3, 4);
   addEdge(graph, 3, 5);
   addEdge(graph, 4, 6);
   addEdge(graph, 5, 6);
   std::cout<<"Is 2 and 6 Connected "<<isConnected(graph, 2, 6)<<"\n";
   
   printGraph(graph);
   bfs(graph, 0);
   dfs(graph, 0);
   removeEdge(graph, 2, 6);
   std::cout<<"Is 2 and 6 Connected "<<isConnected(graph, 2, 6)<<"\n";
   
   printGraph(graph);
   bfs(graph, 0);
   dfs(graph, 0);
   return 0;
}