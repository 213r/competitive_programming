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
    int n; int k;
    cin >> n >> k;
    int idx;
    rep(i, n) {
        int a; cin >> a;
        if (a==1) idx=i; 
    }
    int ret = 0;
    ret += idx/(k-1) + (int)(idx%(k-1) > 0);
    ret += (n-idx-1)/(k-1) + (int)((n-idx-1)%(k-1) > 0);
    cout << ret << endl;
    return 0;
}