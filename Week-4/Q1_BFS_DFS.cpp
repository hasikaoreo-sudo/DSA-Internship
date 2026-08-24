#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : graph[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << endl;
}

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour, graph, visited);
        }
    }
}

int main() {
    int vertices = 6;

    vector<vector<int>> graph(vertices);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};

    BFS(0, graph);

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    DFS(0, graph, visited);
    cout << endl;

    return 0;
}
