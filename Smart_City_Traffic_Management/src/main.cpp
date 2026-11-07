#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

/*
 * Smart City Traffic Management System
 * Core ADS concepts:
 *   - Weighted undirected graph (adjacency list)
 *   - Dijkstra's shortest-path algorithm (min-priority queue)
 *   - BFS for reachability
 *   - Edge-weight updates to model traffic congestion
 *
 * Input weights represent estimated travel time in minutes.
 */

struct Edge {
    int to;
    int travelTime;
};

class TrafficNetwork {
private:
    vector<string> locations;
    unordered_map<string, int> id;
    vector<vector<Edge>> adj;

public:
    int addLocation(const string& name) {
        auto it = id.find(name);
        if (it != id.end()) return it->second;

        int index = static_cast<int>(locations.size());
        id[name] = index;
        locations.push_back(name);
        adj.emplace_back();
        return index;
    }

    bool hasLocation(const string& name) const {
        return id.find(name) != id.end();
    }

    int locationCount() const {
        return static_cast<int>(locations.size());
    }

    const string& locationName(int index) const {
        return locations.at(index);
    }

    void addRoad(const string& from, const string& to, int minutes) {
        if (minutes <= 0) {
            throw invalid_argument("Travel time must be positive.");
        }
        int u = addLocation(from);
        int v = addLocation(to);
        updateOneWay(u, v, minutes);
        updateOneWay(v, u, minutes);
    }

    bool updateRoad(const string& from, const string& to, int minutes) {
        if (minutes <= 0 || !hasLocation(from) || !hasLocation(to)) return false;
        int u = id.at(from), v = id.at(to);
        bool forward = updateExisting(u, v, minutes);
        bool backward = updateExisting(v, u, minutes);
        return forward && backward;
    }

    bool updateExisting(int u, int v, int minutes) {
        for (Edge& edge : adj[u]) {
            if (edge.to == v) {
                edge.travelTime = minutes;
                return true;
            }
        }
        return false;
    }

    void updateOneWay(int u, int v, int minutes) {
        for (Edge& edge : adj[u]) {
            if (edge.to == v) {
                edge.travelTime = minutes;
                return;
            }
        }
        adj[u].push_back({v, minutes});
    }

    void displayRoads() const {
        cout << "\n--- Road Network (travel time in minutes) ---\n";
        for (int u = 0; u < locationCount(); ++u) {
            cout << locations[u] << " -> ";
            for (const Edge& edge : adj[u]) {
                cout << locations[edge.to] << " (" << edge.travelTime << " min)  ";
            }
            cout << '\n';
        }
    }

    void reachableFrom(const string& start) const {
        if (!hasLocation(start)) {
            cout << "Unknown starting location.\n";
            return;
        }

        vector<bool> visited(locationCount(), false);
        queue<int> q;
        int source = id.at(start);
        visited[source] = true;
        q.push(source);

        cout << "\nLocations reachable from " << start << ": ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << locations[u] << (q.empty() ? "" : ", ");
            for (const Edge& edge : adj[u]) {
                if (!visited[edge.to]) {
                    visited[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }
        cout << '\n';
    }

    void shortestPath(const string& start, const string& destination) const {
        if (!hasLocation(start) || !hasLocation(destination)) {
            cout << "Unknown source or destination.\n";
            return;
        }

        const int n = locationCount();
        const int INF = numeric_limits<int>::max();
        vector<int> dist(n, INF), parent(n, -1);

        using State = pair<int, int>; // {distance, vertex}
        priority_queue<State, vector<State>, greater<State>> pq;

        int source = id.at(start);
        int target = id.at(destination);
        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [currentDistance, u] = pq.top();
            pq.pop();

            if (currentDistance != dist[u]) continue;
            if (u == target) break;

            for (const Edge& edge : adj[u]) {
                int candidate = currentDistance + edge.travelTime;
                if (candidate < dist[edge.to]) {
                    dist[edge.to] = candidate;
                    parent[edge.to] = u;
                    pq.push({candidate, edge.to});
                }
            }
        }

        if (dist[target] == INF) {
            cout << "No route is available between these locations.\n";
            return;
        }

        vector<int> path;
        for (int at = target; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        cout << "\nFastest estimated route:\n";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << locations[path[i]];
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << "\nEstimated travel time: " << dist[target] << " minutes\n";
    }
};

void loadDemoNetwork(TrafficNetwork& network) {
    network.addRoad("Central Station", "City Hospital", 8);
    network.addRoad("Central Station", "Tech Park", 12);
    network.addRoad("Central Station", "Market Square", 6);
    network.addRoad("Market Square", "City Hospital", 5);
    network.addRoad("Market Square", "University", 9);
    network.addRoad("City Hospital", "University", 7);
    network.addRoad("Tech Park", "University", 4);
    network.addRoad("Tech Park", "Airport", 15);
    network.addRoad("University", "Airport", 10);
    network.addRoad("Market Square", "Bus Terminal", 7);
    network.addRoad("Bus Terminal", "Airport", 13);
}

int main() {
    TrafficNetwork network;
    loadDemoNetwork(network);

    int choice = -1;
    while (choice != 0) {
        cout << "\n===== SMART CITY TRAFFIC MANAGEMENT =====\n"
             << "1. Display road network\n"
             << "2. Find fastest route (Dijkstra)\n"
             << "3. Update road travel time (simulate traffic)\n"
             << "4. Find reachable locations (BFS)\n"
             << "0. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid menu number.\n";
            continue;
        }

        if (choice == 1) {
            network.displayRoads();
        } else if (choice == 2) {
            string from, to;
            cout << "Enter source location (use underscores for spaces): ";
            cin >> from;
            cout << "Enter destination location (use underscores for spaces): ";
            cin >> to;
            auto normalize = [](string value) {
                replace(value.begin(), value.end(), '_', ' ');
                return value;
            };
            network.shortestPath(normalize(from), normalize(to));
        } else if (choice == 3) {
            string from, to;
            int minutes;
            cout << "Road start (use underscores for spaces): ";
            cin >> from;
            cout << "Road end (use underscores for spaces): ";
            cin >> to;
            cout << "New travel time in minutes: ";
            cin >> minutes;
            replace(from.begin(), from.end(), '_', ' ');
            replace(to.begin(), to.end(), '_', ' ');
            if (network.updateRoad(from, to, minutes)) {
                cout << "Road travel time updated. Re-run route search for the new result.\n";
            } else {
                cout << "Update failed. Check road names and enter a positive time.\n";
            }
        } else if (choice == 4) {
            string start;
            cout << "Starting location (use underscores for spaces): ";
            cin >> start;
            replace(start.begin(), start.end(), '_', ' ');
            network.reachableFrom(start);
        } else if (choice == 0) {
            cout << "Exiting. Drive safely!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
