#include <iostream>
#include <queue>
using namespace std;

#define R 6
#define C 7


char grid[R][C] = {
    {'S', '.', '.' , '#', '.', '.' , '.'},
    {'.', '#', '.' , '.', '.', '#' , '.'},
    {'.', '#', '.' , '.', '.', '.' , '.'},
    {'.', '.', '#' , '#', '.', '.' , '.'},
    {'.', '.', '#' , '#', '.', '.' , '.'},
    {'#', '.', '#' , 'E', '.', '#' , '.'},
};

pair<int, int> direction[4]  {{-1,0},{0,1}, {1,0} , {0, -1}}; // East West North South

bool isValid(int row , int col) {
    return (row >= 0 && col >= 0) && (row < R && col < C);
}

class Node {
public:
    pair<int, int> cord;
    int dist;
    Node(pair<int,int> cord, int dist):cord(cord), dist(dist) {}
};

bool visited[R][C] = {false};

void getNeighbours(const Node curr, queue <Node> &q) {
        for (int i = 0; i < 4; i++) {
            int cr = curr.cord.first + direction[i].first;
            int cc = curr.cord.second + direction[i].second;
            // Skip bound location
            if(isValid(cr, cc) == false || visited[cr][cc] == true || grid[cr][cc] == '#'){
                continue;
            }
            visited[cr][cc] = true;
            q.push(Node({cr,cc},curr.dist + 1));
        }
}

int BFS(char grid[][C]) {
    queue <Node> q;
    q.push(Node({0,0},0));
    visited[0][0] = true;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        if(grid[curr.cord.first][curr.cord.second] == 'E') {
            return curr.dist;
        }
        getNeighbours(curr, q);
    }
    return -1;
}

int main() {
    cout<<"Shortest Path "<<BFS(grid)<<endl;
}