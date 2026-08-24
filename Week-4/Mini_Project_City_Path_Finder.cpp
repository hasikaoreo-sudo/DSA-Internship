#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

int findMinDistance(const vector<int>& distance,
                    const vector<bool>& visited) {
    int minDistance = INF;
    int minIndex = -1;

    for (int i = 0; i < distance.size(); i++) {
        if (!visited[i] && distance[i] < minDistance) {
            minDistance = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void shortestPath(const vector<vector<pair<int, int>>>& graph,
                  int source, int destination,
                  const vector<string>& cities) {

    int n = graph.size();

    vector<int> distance(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    distance[source] = 0;

    for (int count = 0; count < n; count++) {
        int current = findMinDistance(distance, visited);

        if (current == -1)
            break;

        visited[current] = true;

        for (auto edge : graph[current]) {
            int neighbour = edge.first;
            int weight = edge.second;

            if (!visited[neighbour] &&
                distance[current] != INF &&
                distance[current] + weight < distance[neighbour]) {

                distance[neighbour] =
                    distance[current] + weight;

                parent[neighbour] = current;
            }
        }
    }

    if (distance[destination] == INF) {
        cout << "No route found." << endl;
        return;
    }

    vector<int> path;

    int current = destination;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest Route: ";

    for (int i = 0; i < path.size(); i++) {
        cout << cities[path[i]];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;
    cout << "Total Distance: "
         << distance[destination] << " km" << endl;
}

int main() {

    vector<string> cities = {
        "Chennai",
        "Bangalore",
        "Hyderabad",
        "Mumbai",
        "Pune"
    };

    int n = cities.size();

    vector<vector<pair<int, int>>> graph(n);

    // Chennai - Bangalore
    graph[0].push_back({1, 350});
    graph[1].push_back({0, 350});

    // Chennai - Hyderabad
    graph[0].push_back({2, 630});
    graph[2].push_back({0, 630});

    // Bangalore - Hyderabad
    graph[1].push_back({2, 570});
    graph[2].push_back({1, 570});

    // Bangalore - Pune
    graph[1].push_back({4, 840});
    graph[4].push_back({1, 840});

    // Hyderabad - Mumbai
    graph[2].push_back({3, 710});
    graph[3].push_back({2, 710});

    // Mumbai - Pune
    graph[3].push_back({4, 150});
    graph[4].push_back({3, 150});

    cout << "Available Cities:\n";

    for (int i = 0; i < n; i++) {
        cout << i << ". " << cities[i] << endl;
    }

    int source, destination;

    cout << "\nEnter source city number: ";
    cin >> source;

    cout << "Enter destination city number: ";
    cin >> destination;

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n) {

        cout << "Invalid city number!" << endl;
        return 0;
    }

    cout << "\nFrom: " << cities[source] << endl;
    cout << "To: " << cities[destination] << endl;

    shortestPath(graph, source, destination, cities);

    return 0;
}
