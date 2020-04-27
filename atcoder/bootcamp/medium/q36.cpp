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

ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ll n; ll x;
    cin >> n >> x;
    vector<ll> xs(n);
    rep(i, n) cin >> xs[i];
    ll d = abs(x-xs[0]);
    rep(i, n-1) d = gcd(d, abs(x-xs[i+1]));
    cout << d << endl;
    return 0;
}