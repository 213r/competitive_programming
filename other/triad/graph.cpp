#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define pii pair<int, int>

class UnionFind {
    vector<int> par;
    vector<int> rank;
public: 
    UnionFind(int n): par(n), rank(n, 0) {
        iota(par.begin(), par.end(),0);
    }
    bool same(int x, int y) {
        int px = find(x); 
        int py = find(y);
        return px == py;
    }
    void unite(int x, int y) {
        int px = this->find(x); 
        int py = this->find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
            par[px] = py;
        } else { 
            par[py] = px;
            if (rank[px] == rank[py]) rank[px]++;
        } 
    }
private:
    int find(int x) {
        if (x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
};

template<class T> struct Edge{
    int from, to; T cost;
    edge(int f, int t, T c){
        from = f; to = t; cost = c;
    }
};
 
template<class T> struct Graph{
    vector<vector<Edge<T>>> G;
    int n;
 
    Graph(int n_){
        n = n_;
        G.resize(n);
    }
 
    void add_edge(int f, int t, T c){
        G[f].emplace_back(f, t, c);
    }
 
    pair<bool, vector<T>> bellman_ford(int s){
        T INF = numeric_limits<T>::max();
        vector<T> d(n, INF);
        vector<Edge<T>> E;
        REP(i, n)for(Edge<T> &e: G[i]) E.push_back(e);
        d[s] = 0;
        REP(i, n)for(Edge<T> &e: E){
            if(d[e.from] != INF && d[e.from] + e.cost < d[e.to]){
                d[e.to] = d[e.from] + e.cost;
                if(i == n-1) return make_pair(true, d);
            }
        }
        return make_pair(false, d);
    }
 
    vector<T> dijkstra(int s){
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        T INF = numeric_limits<T>::max();
        vector<T> d(n, INF);
        d[s] = 0;
        que.push(P((T)0, s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(Edge<T> &e : G[v]){
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
        return d;
    }
 
    vector<vector<T>> warshall_floyd(){
        T INF = numeric_limits<T>::max();
        vector<vector<T>> d = vector<vector<T>>(n, vector<T>(n, INF));
        REP(i, n){
            for(Edge<T> &e: G[i]) d[i][e.to] = e.cost;
            d[i][i] = 0;
        }
        REP(k, n)REP(i, n)REP(j, n)
        if(d[i][k] < INF && d[k][j] < INF){
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
        return d;
    }
 
    T kruskal(){
        vector<Edge<T>> E;
        REP(i, n)for(Edge<T> &e: G[i]) E.push_back(e);
        sort(E.begin(), E.end(), 
            [](const Edge<T> &e1, const Edge<T> &e2){return e1.cost < e2.cost;}
        );
        UnionFind uf(n);
        T res = 0;
        for(Edge<T> &e: E){
            if(!uf.same(e.from, e.to)){
                uf.unite(e.from, e.to);
                res += e.cost;
            }
        }
        return res;
    }
 
    pair<bool, vector<int>> toposo(){
        vector<int> ret(n, -1), in(n, 0);
        Rep(i, n)for(Edge<T> &e: G[i]) ++in[e.to];
        int cur = 0;
        stack<int> st;
        rep(i, n)if(!in[i]) st.push(i);
        if(st.empty()) return make_pair(false, ret);
        while(!st.empty()){
            int v = st.top(); st.pop();
            ret[cur++] = v;
            for(Edge<T> &e: G[v]){
                if(!in[e.to]) return make_pair(false, ret);
                --in[e.to];
                if(!in[e.to]) st.push(e.to);
            }
        }
        return make_pair(cur==n, ret);
    }
 
    bool has_cycle(){
        return !toposo().fi;
    }
 
    void scc_dfs(int v, vector<bool> &used, vector<int> &vs){
        used[v] = true;
        for(Edge<T> &e: G[v])if(!used[e.to]) scc_dfs(e.to, used, vs);
        vs.push_back(v);
    }
 
    void scc_rdfs(int v, int k, vector<int> &cmp, vector<bool> &used, vector<vector<int>> &rG){
        used[v] = true;
        cmp[v] = k;
        for(int nv: rG[v])if(!used[nv]) scc_rdfs(nv, k, cmp, used, rG);
    }
 
    pair<int, vector<int>> scc(){
        vector<vector<int>> rG(n);
        REP(i, n)for(Edge<T> &e: G[i]) rG[e.to].push_back(i);
        vector<bool> used(n, false);
        vector<int> vs;
        vector<int> cmp(n);
        REP(i, n)if(!used[i]) scc_dfs(i, used, vs);
        fill(used.begin(), used.end(), false);
        int k = 0;
        rrep(i, n)if(!used[vs[i]]) scc_rdfs(vs[i], k++, cmp, used, rG);
        return make_pair(k, cmp);
    }
 
    int bridge_dfs(int v, int pv, int &idx, vector<int> &ord, vector<int> &low, vector<pii> &bridge){
        ord[v]=low[v]=idx++;
        for(auto &e: G[v])if(e.to!=pv){
            int nv=e.to;
            if(ord[nv]<0){
                chmin(low[v], bridge_dfs(nv, v, idx, ord, low, bridge));
                if(low[nv]>ord[v]) bridge.emplace_back(min(v, nv), max(v, nv));
            }
            else chmin(low[v], ord[nv]);
        }
        return low[v];
    }
 
    vector<pii> get_bridge(){
        vector<int> ord(n, -1), low(n, -1);
        vector<pii> bridge;
        int idx=0;
        bridge_dfs(0, -1, idx, ord, low, bridge);
        sort(bridge.begin(), bridge.end());
        bridge.erase(unique(bridge.begin(), bridge.end()), bridge.end());
        return bridge;
    }
 
    int art_dfs(int v, int prev, int &idx, vector<int> &ord, vector<int> &low, vector<int> &art){
        ord[v]=low[v]=idx++;
        for(auto &e: G[v])if(e.to!=prev){
            int nv=e.to;
            if(ord[nv]<0){
                chmin(low[v], art_dfs(nv, v, idx, ord, low, art));
                if((prev<0 && ord[nv]!=1) || (prev>=0 && low[nv]>=ord[v])){
                    art.push_back(v);
                }
            }
            else chmin(low[v], ord[nv]);
        }
        return low[v];
    }
 
    vector<int> get_art(){
        vector<int> ord(n, -1), low(n, -1), art;
        int idx=0;
        art_dfs(0, -1, idx, ord, low, art);
        sort(art.begin(), art.end());
        art.erase(unique(art.begin(), art.end()), art.end());
        return art;
    }
};