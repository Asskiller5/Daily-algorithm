#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int lower_bound;
    int current_cost;
    int cur_node;
    vector<bool> visited;
    vector<int> path;

    bool operator<(const Node& other) const {
        return lower_bound > other.lower_bound;
    }
};

int calculateLowerBound(int n, const vector<vector<int> >& dist, const Node& node, const vector<int>& min_edge) {
    int total_min = 0;
    for (int i = 1; i <= n; ++i) {
        if (!node.visited[i]) {
            total_min += min_edge[i];
        }
    }
    return node.current_cost + total_min;
}

pair<int, vector<int> > tspBranchAndBound(int n, const vector<vector<int> >& dist) {
    const int INF = INT_MAX;
    vector<int> min_edge(n + 1, INF);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && dist[i][j] < min_edge[i]) {
                min_edge[i] = dist[i][j];
            }
        }
    }

    priority_queue<Node> pq;
    vector<bool> initial_visited(n + 1, false);
    initial_visited[1] = true;

    Node start;
    start.lower_bound = 0;
    start.current_cost = 0;
    start.cur_node = 1;
    start.visited = initial_visited;
    start.path.push_back(1);
    start.lower_bound = calculateLowerBound(n, dist, start, min_edge);

    pq.push(start);
    int best_cost = INF;
    vector<int> best_path;

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.lower_bound >= best_cost) {
            continue;
        }

        if (curr.path.size() == n) {
            int total_cost = curr.current_cost + dist[curr.cur_node][1];
            if (total_cost < best_cost) {
                best_cost = total_cost;
                best_path = curr.path;
                best_path.push_back(1);
            }
            continue;
        }

        for (int v = 1; v <= n; ++v) {
            if (!curr.visited[v] && dist[curr.cur_node][v] != INF) {
                Node next_node = curr;
                next_node.cur_node = v;
                next_node.visited[v] = true;
                next_node.current_cost += dist[curr.cur_node][v];
                next_node.path.push_back(v);
                next_node.lower_bound = calculateLowerBound(n, dist, next_node, min_edge);

                if (next_node.lower_bound < best_cost) {
                    pq.push(next_node);
                }
            }
        }
    }

    return make_pair(best_cost, best_path);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    const int INF = INT_MAX;
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    pair<int, vector<int> > result = tspBranchAndBound(n, dist);
    int cost = result.first;
    vector<int> path = result.second;

    cout << cost << endl;
    cout << "<";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) cout << ",";
        cout << path[i];
    }
    cout << ">" << endl;

    return 0;
}