#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using P = pair<int, int>;
const int INF = 1 << 9;
struct edge{
    int to; 
    int cost;
};

vector<int> dikjastra(const vector<vector<edge>>& graph, int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> d(graph.size(), INF);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        auto p = que.top(); que.pop();
        int v = p.second;
        if (p.first > d[v]) continue;
        for (auto& e : graph[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<edge>> graph(n);
    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge to_a, to_b;
        to_a.to = b; to_a.cost = c;
        to_b.to = a; to_b.cost = c;
        graph[a].emplace_back(to_a);
        graph[b].emplace_back(to_b);
    }
    auto d = dikjastra(graph, 0);
    for (int i = 0; i < n; ++i) {
        cout << i << "," << d[i] << endl;
    }
    return 0;
}