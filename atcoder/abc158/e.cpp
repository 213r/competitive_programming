#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    ll ans = 0;
    if (p == 2 || p == 5) {
        rep(i, n) {
            if ((s[i]-'0')%p==0) ans += i+1;
        }
        cout << ans << endl;
        return 0;
    } 
    vector<int> smod(n);
    smod[0] = (s[n-1]-'0') % p;
    int tenmod = 1;
    rep1(i, n) {
        tenmod = tenmod * 10 % p;
        smod[i] = (tenmod * (s[n-i-1]-'0') + smod[i-1]) % p;
    } 
    vector<ll> counts(p, 0);
    rep(i, n) counts[smod[i]]++;
    ans += counts[0];
    rep(i, p) {
        if (counts[i]) {
            ans += counts[i] * (counts[i]-1) / 2;
        }
    }
    cout << ans << endl; 
    return 0;
}