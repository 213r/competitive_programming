#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

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
