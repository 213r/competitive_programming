#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 
const ll INF = 1e18;

using P = pair<int, int>;

class Dikjastra {
private:
    vector<vector<P>> graph;
public:
    Dikjastra(int size): graph(size, vector<P>())    
    {}

    void set_node(int i, int j, int cost) {
        graph[i].push_back({cost, j});
        graph[j].push_back({cost, i});
    }

    vector<int> calc(int s) {
        priority_queue<P, vector<P>, greater<P>> que;
        vector<int> d(graph.size(), INF);
        d[s] = 0;
        que.push(P(0, s));
        while (!que.empty()) {
            auto p = que.top(); que.pop();
            int v = p.second;
            if (p.first > d[v]) continue;
            for (auto& e : graph[v]) {
                int to = e.second; 
                int c = e.first;
                if (d[to] > d[v] + c) {
                    d[to] = d[v] + c;
                    que.push(P(d[to], to));
                }
            }
        }
        return d;
    }
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> amat(h, vector<int>(w, 0));
    REP(i, h) REP(j, w) cin >> amat[h-i-1][j];

    Dikjastra dj(h*w);
    REP(i, h) {
        REP(j, w) {
            int a = i * w + j;
            if (j < w - 1) {
                int b = i * w + j + 1;
                dj.set_node(a, b, c)
            } 
            int b2 = (i + 1) * w + j;
        }
    }
    return 0;
}