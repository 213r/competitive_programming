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
    ll a; ll b; ll c; ll d;
    cin >> a >> b >> c >> d;
    ll l = c*d/gcd(c, d);
    ll ret =  b - b /c  - b/d + b/l; 
    --a; 
    ret -= a - a/c - a/d + a/l;
    cout << ret << endl; 
    return 0;
}