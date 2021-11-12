#include <iostream>
#include <list>
#include<stack>
#include <vector>

using namespace std;

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

class AdjListNode {
    const int v;
    const int weight;
public:
    AdjListNode(int _v, int _weight) : v(_v), weight(_weight) {}

    int getV() const {
        return v;
    }

    int getWeight() const {
        return weight;
    }
};

class Graph {
    list<const AdjListNode>*g;
    const int total_nodes;

    void dfs_helper(int u, vector<bool> & visited, stack<int> &stack) {
        visited[u] = true;
        for (auto iter = g[u].begin(); iter != g[u].end(); iter++) {
            if(visited[iter->getV()] == false) {
                dfs_helper(iter->getV(), visited, stack);
            }
        }
        stack.push(u);
    }

    stack<int> topological_sort() {
        vector<bool> visited(total_nodes,false);
        stack<int> stack;
        for (int i = 0; i < total_nodes; i++) {
            if(visited[i] == false) {
                dfs_helper(i, visited, stack);
            }
        }
        return stack;
    }
public:
    Graph(int v):total_nodes(v) {
        g = new list<const AdjListNode>[v];
    }
    void addEdge(int u, int v, int weight) {
        g[u].push_back(AdjListNode(v, weight));
    }

    void shortest_path(int from) {
        stack<int> stack = topological_sort();
        vector<int>dist(total_nodes, INT_MAX);
        dist[from] = 0;
        while (!stack.empty()) {
            int u = stack.top(); stack.pop();
            if(dist[u] != INT_MAX) {
                for (auto iter = g[u].begin(); iter != g[u].end(); iter++) {
                    if(dist[iter->getV()] > dist[u] + iter->getWeight()) {
                        dist[iter->getV()] = dist[u] + iter->getWeight();
                    }
                }
            }
        }
        
        for (int i = 0; i < total_nodes; i++) {
            (dist[i] == INT_MAX) ? cout<<"INF " : cout<<dist[i]<<" "; 
        }
    }

    void longest_path(int from) {
        stack<int> stack = topological_sort();
        vector<int>dist(total_nodes, INT_MIN);
        dist[from]  = 0;
        while (!stack.empty()) {
            int u = stack.top(); stack.pop();
            if(dist[u] != INT_MIN) {
                for (const AdjListNode neighbour : g[u]) {
                    if(dist[neighbour.getV()] < dist[u] + neighbour.getWeight()) {
                        dist[neighbour.getV()] = dist[u] + neighbour.getWeight();
                    }
                }
            }
        }

        for (int i = 0; i < total_nodes; i++) {
            (dist[i] == INT_MIN) ? cout<<"INF " : cout<<dist[i]<<" "; 
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    for (int i = 0; i < 6 ; i++) {
        cout<<"Shortest Path from "<<i<<" { ";
        g.shortest_path(i);
        cout<<" }"<<endl;
    }

    cout<<endl;
    for (int i = 0; i < 6 ; i++) {
        cout<<"Longest Path from "<<i<<" { ";
        g.longest_path(i);
        cout<<" }"<<endl;
    }

}