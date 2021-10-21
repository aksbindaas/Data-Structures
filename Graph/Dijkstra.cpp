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
#include <list>

class AdjListNode {
private:
    int v;
    int weight;
public:
    AdjListNode(int node, int weight):v(node), weight(weight) {
    }
    int getV() {
        return v;
    }
    int getWeight() {
        return weight;
    }
    std::string operator() () {
        return std::to_string(v) +" "+std::to_string(weight);
    }
};
class Graph {
private:
    int v;
    std::list<AdjListNode> *adj;
    //std::vector<std::vector<std::pair<int, int>>> graph(9, std::vector<std::pair<int, int>>(9));
public:
    Graph(int nodes) {
        this->v = nodes;
        adj = new std::list<AdjListNode>[v];
    }

    ~Graph () {
        delete [] adj;
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight}); // Add v to u's list
        adj[v].push_back({u, weight}); // Add v to u's list
    }

    std::vector<int> dijkstra(int start) {
        std::vector<int> distance(v, INT_MAX);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(start, 0));
        distance[start] = 0;
        while(!pq.empty()) {
            // get min distance from pq
            const int u = pq.top().first; pq.pop();
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                AdjListNode node = *i;
                
                const int v = node.getV();
                const int weight = node.getWeight();
                if(distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(std::make_pair(v, distance[v]));
                }
            }
        }
        return distance;
}
};

int main() {
    Graph graph(9);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);
    
    std::vector<int> dist = graph.dijkstra(0);
    for(int i = 0; i < dist.size() ; i++) {
        std::cout<<"Distance between 0 -> "<<i<<" is "<<dist[i]<<std::endl;
    }
    return 0;
}