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
    int n, m; 
    unordered_map<int, int> ds, ts;
    cin >> n;
    rep(i, n) {
        int d; cin >> d;
        ds[d]++; 
    }
    cin >> m;
    rep(i, m) {
        int t; cin >> t;
        ts[t]++; 
    }
    if (n < m) {
        cout << "NO" << endl;
        return 0;
    }
    for(auto& t : ts) {
        if (ds[t.first] < t.second) {
            cout << "NO" << endl;
            return 0;
        }
    } 
    cout << "YES" << endl;
    return 0;
}