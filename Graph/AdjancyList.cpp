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

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#define V 7
#define VISITED true
#define NOT_VISITED false

void addEdge(std::array<std::vector<int>,V> &graph, int v1, int v2) {
    // O(1)
    graph.at(v1).push_back(v2);
    graph.at(v2).push_back(v1);
}

void removeEdge(std::array<std::vector<int>,V> &graph, int v1, int v2) {
    // O(N)
    graph[v1].erase(std::find(graph[v1].begin(), graph[v1].end(),v2));
    graph[v2].erase(std::find(graph[v2].begin(), graph[v2].end(),v1));
}

 bool isConnected(std::array<std::vector<int>,V> &graph, int v1, int v2) {
     // O(1)
     return std::find(graph[v1].begin(), graph[v1].end(),v2) != graph[v1].end(); 
 }

void printGraph(std::array<std::vector<int>,V> &graph) {
    for (int i=0; i< graph.size(); i++) {
        std::cout<<i<<":";
        for(int v : graph[i]) {
            std::cout<<"->"<<v;
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void bfs(std::array<std::vector<int>,V> &graph, int startPoint) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    q.push(startPoint);
    visited[startPoint] = VISITED;
    std::cout<<"\nBFS : ";
    while(!q.empty()) {
        const int v = q.front(); q.pop();
        std::cout<<v<<" ";
        for (int connection  : graph[v]) {
            if(visited[connection] == NOT_VISITED) {
                q.push(connection);
                visited[connection] = VISITED;
            }
        }
    }
}

void dfs(std::array<std::vector<int>,V> &graph, int startPoint) {
    std::vector<bool> visited(graph.size(), false);
    std::stack<int> q;
    q.push(startPoint);
    visited[startPoint] = VISITED;
    std::cout<<"\nDFS : ";
    while(!q.empty()) {
        const int v = q.top(); q.pop();
        std::cout<<v<<" ";
        for (int connection  : graph[v]) {
            if(visited[connection] == NOT_VISITED) {
                q.push(connection);
                visited[connection] = VISITED;
            }
        }
    }
}

int main() {
    // Adjancy List
    std::array<std::vector<int>,V> graph;
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
}