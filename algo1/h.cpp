#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n, q;
    cin >> n;
    vector<int> cs(n);
    int tot_min = 2e9, odd_min = 2e9; 
    REP(i, n) {
        cin >> cs[i];
        tot_min = min(tot_min, cs[i]);
        if(i%2==0) odd_min = min(odd_min, cs[i]);
    }
    cin >> q;
    ll ret = 0, odd_only_sell = 0, all_sell = 0;
    REP(i, q) {
        int s, x;
        ll a;
        cin >> s;
        if (s == 1) {
            cin >> x >> a;
            --x;
            int c = cs[x] - all_sell;
            if (x%2==0) c -= odd_only_sell;
            if (a <= c) {
                cs[x] -= a;
                ret += a;
                if (cs[x] < tot_min) tot_min = cs[x];
                if (x%2==0 && cs[x] < odd_min) odd_min = cs[x];
            } 
        } else if (s == 2) {
            cin >> a;
            if(a <= odd_min) {
                ret +=  a * ((n+1)/2);
                odd_only_sell += a;
                odd_min -= a;
                tot_min = min(odd_min, tot_min);
            }
        } else {
            cin >> a;
            if (a <= tot_min) {
                ret += a * n;
                tot_min -= a; 
                odd_min -= a;
                all_sell += a;
            } 
        }
    } 
    cout << ret << endl;
    return 0;
}