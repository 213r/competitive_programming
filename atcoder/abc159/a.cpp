#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

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
    return x / y; 
}


int main() {
    int n, m; 
    cin >> n >> m; 
    cout << COM2(n, 2) + COM2(m, 2) << endl;

}