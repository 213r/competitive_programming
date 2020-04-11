#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> size;
    UnionFind(int N) : par(N), size(N, 1) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        par[x] = root(par[x]);
        return par[x];
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        size[ry] += size[rx];
    }

    int get_size(int x) {
        int rx = root(x);
        return size[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    vector<int> fcnts(n, 0); 
    vector<vector<int>> ks(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
        fcnts[a]++; fcnts[b]++;
    }
    rep(i, k) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        ks[c].push_back(d);
        ks[d].push_back(c);
    }
    vector<int> rets(n);
    rep(i, n) {
        int c = -1; 
        c += uf.get_size(i);
        c -= fcnts[i];
        for (int k : ks[i]) {
            if (uf.same(i, k)) c--;
        }
        rets[i] = c;
    }
    rep(i, n) cout << rets[i] << " ";
    cout << endl;
    return 0;
}