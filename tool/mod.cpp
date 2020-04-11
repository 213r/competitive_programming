#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
typedef long long ll;
const int MOD = 1000000007; 
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll POW(ll n, ll k) {
    if (k==0) return 1;
    ll ret = 1;
    while (k > 0) {
        if (k&1) ret = (ret * n) % MOD;
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

