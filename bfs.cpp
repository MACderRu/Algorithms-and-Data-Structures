#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
public:
    Graph(int n) {
        weight = 6;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            edges.push_back(v);
        }
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> shortest_reach(int start) {
        queue<int> q({start});
        vector<bool> used(edges.size());
        vector<int> d(edges.size(), -1);
        used[start] = true;
        d[start] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i=0; i < edges[v].size(); i++) {
                int cur_v = edges[v][i];
                if (!used[cur_v]) {
                    used[cur_v] = true;
                    q.push(cur_v);
                    d[cur_v] = d[v] + weight;
                }
            }
        }
        vector<int> path;
        for (int i = 0; i < edges.size(); i++) {
            path.push_back(d[i]);
        }

        return path;
    }
private:
    int weight;
    vector<vector<int>> edges;
};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        int n, m;
        cin >> n;
        Graph graph(n);
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}