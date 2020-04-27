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
    int smin = 101;
    int tot = 0;
    rep(i, n) {
        int s; cin >> s;
        if (s%10) smin = min(smin, s);
        tot += s; 
    }
    int ret = 0;
    if (tot%10) ret = tot;
    else {
        if (smin != 101) ret = tot-smin;
    } 
    cout << ret << endl; 
    return 0;
}