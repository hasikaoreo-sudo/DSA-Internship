#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5;

int findMinDistance(vector<int>& distance, vector<bool>& visited) {
    int minDistance = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && distance[i] < minDistance) {
            minDistance = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(vector<vector<int>>& graph, int source) {
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);

    distance[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int current = findMinDistance(distance, visited);

        if (current == -1)
            break;

        visited[current] = true;

        for (int neighbour = 0; neighbour < V; neighbour++) {
            if (graph[current][neighbour] != 0 &&
                !visited[neighbour] &&
                distance[current] != INT_MAX &&
                distance[current] + graph[current][neighbour] < distance[neighbour]) {

                distance[neighbour] =
                    distance[current] + graph[current][neighbour];
            }
        }
    }

    cout << "Shortest distances from source " << source << ":" << endl;

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " = ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 3, 0, 0},
        {10, 0, 1, 2, 0},
        {3, 1, 0, 8, 2},
        {0, 2, 8, 0, 7},
        {0, 0, 2, 7, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}
