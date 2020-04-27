#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const int MOD = 1000000007; 


int main() {
    int n,m;
    cin >> n >> m;
    vector<int> xs(m);
    rep(i, m) cin >> xs[i];
    if (n >= m) {
        cout << 0 << endl; 
        return 0;
    }
    vector<int> ds(m-1);
    sort(xs.begin(), xs.end());
    rep(i, m-1) ds[i] = xs[i+1] - xs[i];
    sort(ds.begin(), ds.end());
    int ret = 0;
    rep(i, m-n) ret += ds[i];
    cout << ret << endl; 
    return 0;
}