#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

unordered_map<int ,int> calc_pdeconv(int a) {
    unordered_map<int, int> ret;
    for (int p = 2; p*p <= a; ++p) {
        while(a%p==0) {
            ret[p] += 1;
            a /= p;
        }
    }
    if (a != 1) ret[a] = 1;
    return ret;
}

ll modpow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n&1) res = res*x%MOD;
        x = x * x % MOD;
        n >>= 1;
    } 
    return res;
} 

int main() {
    int n, l=1;
    cin >> n;
    // vector<unordered_map<int, int>> v_apmap;
    vector<int> as;
    unordered_map<int, int> lpmap;
    rep(i, n) {
        int a;
        cin >> a; 
        auto amap = calc_pdeconv(a);
        for (auto& ap : amap) {
            lpmap[ap.first] = max(lpmap[ap.first], ap.second);
        } 
        as.push_back(a); 
        //v_apmap.emplace_back(amap); 
    }

    ll c = 1;
    for (auto e : lpmap) {
        c = (c * modpow(e.first, e.second)) % MOD;
    } 

    ll ret = 0;
    for (int a : as) {
        ll b = (c * modpow((ll)a, MOD-2)) % MOD;
        ret = (ret + b) % MOD;
    } 
    cout << ret << endl;
    return 0;
}