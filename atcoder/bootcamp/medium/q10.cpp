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
    const int MAX = 100000;
    vector<int> as(MAX, 0);
    rep(i, n) {
        int a; cin >> a;
        as[a]++; 
    }
    int ret = 0;
    rep(i, as.size()-2) {
        int cnt = as[i] + as[i+1] + as[i+2];
        ret = max(ret, cnt); 
    }
    cout << ret << endl;
    return 0;
}