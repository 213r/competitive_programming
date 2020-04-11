#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

ll POW(ll n, ll k) {
    if (k==0) return 1;
    ll ret = 1;
    while (k > 0) {
        if (k&1) ret = ret * n % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return ret;
}

ll FACT(ll n, ll k) {
    ll ret = 1;
    for (int i = 0; i < k; ++i) {
        ret = ret * (n - i) % MOD;
    }
    return ret;
}

ll COM2(ll n, ll k) {
    ll x = FACT(n, k);
    ll y = FACT(k, k);
    ll mody = POW(y, MOD-2);
    return x * mody % MOD; 
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ret = POW(2, n);
    ret -= 1;
    ret -= COM2(n, a);
    ret -= COM2(n, b);
    while (ret < 0) ret += MOD;
    cout << ret << endl;
}