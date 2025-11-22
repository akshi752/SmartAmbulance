#include "../include/RouteFinder.h"
#include <limits>
#include <algorithm>
#include <climits>

pair<int, vector<string>> RouteFinder::dijkstra(const string &source, const string &destination) {
    unordered_map<string, int> dist;       
    unordered_map<string, string> parent;   

    for (auto city : cityMap.getAdjList()) {
        dist[city.first] = INT_MAX;
    }
    dist[source] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        string u = top.second;

        if (d > dist[u]) continue;

        for (auto edge : cityMap.getAdjList().at(u)) {
            int newDist = dist[u] + edge.distance;

            if (newDist < dist[edge.destination]) {
                dist[edge.destination] = newDist;
                parent[edge.destination] = u;
                pq.push({newDist, edge.destination});
            }
        }
    }

    // ---- Minimal Fix: Check if destination reachable ----
    if (dist[destination] == INT_MAX) {
        return {INT_MAX, {}};
    }

    // Build path
    vector<string> path;
    string temp = destination;

    while (temp != source) {
        path.push_back(temp);

        if (parent.find(temp) == parent.end()) {
            return {INT_MAX, {}};
        }

        temp = parent[temp];
    }

    path.push_back(source);
    reverse(path.begin(), path.end());

    return {dist[destination],path};
}
