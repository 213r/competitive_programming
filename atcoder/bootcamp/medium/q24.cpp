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
    ll n, a, b;
    cin >> n >> a >> b;
    ll ret;
    if (a > b) ret = 0; 
    else if (n == 1) ret = (a==b) ? 1 : 0;
    else {
        ret = (n-1)*b+a;
        ret -= (n-1)*a+b;
        ret += 1;
    }
    cout << ret << endl;
    return 0;
}