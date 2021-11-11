#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
#define V 13
class Graph {
private:
    vector<vector<int>>g;
    void dfsHelper(int start, bool *visited, stack<int> &stack) {
        visited[start] = true;
        for (auto u : g[start]) {
            if(visited[u] == false) {
                dfsHelper(u, visited, stack);
            }
        }
        stack.push(start);
    }

public:
    Graph(int v) {
        for (int i = 0 ; i < V ; i++) {
            g.push_back(vector<int>());
        }

    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
    }

    void topologicalSort() {
        bool visited[V] = {false};
        stack<int> stack;

        for (int i=0; i < V; i++) {
            if(visited[i] == false) {
                dfsHelper(i, visited, stack);
            }
        }

        while (!stack.empty()) {
            cout<<(char)('A'+stack.top())<<" ";
            stack.pop();
        }
        cout<<endl;
        
    }
};

int main() {
    Graph g(13);
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(0,3);
    g.addEdge(3,6);
    g.addEdge(3,7);
    g.addEdge(4,0);
    g.addEdge(4,5);
    g.addEdge(5,10);
    g.addEdge(5,9);
    g.addEdge(6,8);
    g.addEdge(7,8);
    g.addEdge(8,11);
    g.addEdge(9,11);
    g.addEdge(9,12);
    g.addEdge(10,9);

    g.topologicalSort();
    return 0;
}
