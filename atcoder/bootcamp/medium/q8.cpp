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
    int n;
    cin >> n;
    vector<int> as(9, 0);
    rep(i, n) {
        int a; 
        cin >> a;
        int idx = min(a/400, 8);
        ++as[idx]; 
    }
    int vmin = 0;
    rep(i, 8) if(as[i]) ++vmin;
    int vmax = vmin + as[8];
    if (vmin == 0) vmin = 1;
    cout << vmin << " " << vmax << endl; 
    return 0;
}