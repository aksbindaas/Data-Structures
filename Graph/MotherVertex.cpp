#include <iostream>
#include <list>
#include<vector>
#include <algorithm>

using namespace std;

class Graph {
    list<int>*g;
    const int V;

    void dfs_utils(int u, vector<bool> &visited) {
        visited[u] = true;
        for (auto iter = g[u].begin(); iter != g[u].end() ; iter++) {
            if(visited[*iter] == false) {
                dfs_utils(*iter, visited);
            }
        }
    }
public:
    Graph(int v) :V(v)  {
        g = new list<int>[v];
    }

    void addEdge(int u, int v) {
        g[u].push_back(v);
    }

    int mother_vertex() {
        vector<bool> visited(V, false);
        int mother_vertex = 0;
        for (int i = 0; i< V ; i++) {
            if(visited[i] == false) {
                dfs_utils(i, visited);
                mother_vertex = i;
            }
        }
        fill(visited.begin(), visited.end(), false);
        dfs_utils(mother_vertex, visited);
        
        if(find(visited.begin(), visited.end(), false) == visited.end())  {
            return mother_vertex;
        }
        return -1;
    }

};


int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
 
    cout << "A mother vertex is " << g.mother_vertex()<<endl;
 
    return 0;
    return 0;
}