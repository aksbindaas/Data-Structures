/* 
            8        7
        (1)------(2)---(3)
      4 /  |      / \    |  \ 9
       /   |     /2  \ 4 |   \  
      (0)  |11 (8)    \  |  (4)
       \   |  / |      \ |  / 
     8  \  | /7 | 6     \| / 10
         (7)----(6)-----(5)
             1       2
*/


#include <iostream>
#include <queue>
#include <vector>

void addEdge(std::vector<std::vector<std::pair<int,int>>> &graph, int u, int v, int weight) {
    graph[u].push_back(std::make_pair(v, weight));
    graph[v].push_back(std::make_pair(u, weight));
}

std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int>>>&graph, int start) {
    
    std::vector<int> distance(graph.size(), INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(start, 0));
    distance[start] = 0;
    while(!pq.empty()) {
        // get min distance from pq
        const int u = pq.top().first; pq.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            const int v = graph[u][i].first;
            const int weight = graph[u][i].second;
            if(distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(std::make_pair(v, distance[v]));
            }
        }
    }
    return distance;
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> graph(9, std::vector<std::pair<int, int>>(9));
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    
    std::vector<int> dist = dijkstra(graph, 0);
    for(int i = 0; i < dist.size() ; i++) {
        std::cout<<"Distance between 0 -> "<<i<<" is "<<dist[i]<<std::endl;
    }
    return 0;
}