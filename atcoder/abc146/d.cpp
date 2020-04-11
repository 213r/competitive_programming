#include <bits/stdc++.h>
using namespace std;

int dfs(int node, pair<int, int>& pnode,
    vector<vector<pair<int, int>>>& edges,
    vector<int>& colors) {
    int ci = 1;
    int maxci = 1;
    for (int i = 0; i < edges[node].size(); ++i) {
        auto tpair = edges[node][i];
        int e = tpair.first, tn = tpair.second;  
        cout << node << "," << e << "," << tn << endl;
        if (tn == pnode.second) continue;
        if (ci == colors[pnode.first]) ++ci;
        colors[e] = ci;
        pair<int, int> newpnode = {e, node};
        dfs(tn, newpnode,  edges, colors);
    }
    return 1;
}

int main () {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> edges(n+1, vector<pair<int, int>>());
    for (int i = 1; i <= n-1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back({i, b}); 
        edges[b].push_back({i, a}); 
    }
    vector<int> colors(n, 0);
    pair<int, int> tmp = {0,0};
    int k = dfs(1, tmp, edges, colors);
    cout << k << endl;
    for (int i = 1; i <= n-1; ++i) cout << colors[i] << endl;
    return 0;
}