#include <bits/stdc++.h>
#include <algorithm>
#include "unionfind.cpp"
using namespace std;

struct edge{
    int from; 
    int to; 
    int cost;
};

int kruskul(vector<edge>& graph, int v) {
    sort(graph.begin(), graph.end(), 
        [](auto& a, auto& b) {return a.cost < b.cost;}
    );    
    int ret = 0;
    UnionFind uf(v);
    for (auto& e : graph) {
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            ret += e.cost;
        }
    } 
    return ret;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<edge> graph(n);
    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge e;
        e.from = a; e.to = b; e.cost = c; 
        graph.emplace_back(e);
    }
    cout << kruskul(graph, n) << endl;
    return 0;
}