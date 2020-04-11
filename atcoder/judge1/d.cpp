#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return gcd(b, a%b);
}
vector<int> calc_ps(int a0) {
    vector<int> ps;
    for(int d = 2; d * d <= a0; ++d) {
        if (a0%d == 0) {
            ps.push_back(d);
            while(a0%d == 0) a0 /= d;
        } else {
            ++d;
        }
    }
    if(a0 > 1) ps.push_back(a0);
    return ps;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), s(q);
    REP(i, n) cin >> a[i]; 
    REP(i, q) cin >> s[i];
    auto ps = calc_ps(a[0]);
    unordered_set<int> pset(ps.begin(), ps.end());
    unordered_map<int, int> pmap;
    int g = a[0];
    FOR(i, 1, n) {
        for(int p : pset) {
            if (a[i]%p) {
                pmap[p] = i+1;
                pset.erase(p); 
            }
        }
        g = gcd(a[i], g);
        if (g==1) break;
    }
    // for(auto& kv : pmap) cout << kv.first << "," << kv.second << endl;
    REP(i, q) {
        int h = gcd(s[i], g);
        if (h > 1) {
            cout << h << endl;
        } else {
            int ret = n;
            for(auto& kv : pmap) {
                if (s[i]%kv.first == 0) {
                    ret = min(ret, kv.second);
                } else {
                    ret = 1;
                    break;
                }
            }
            cout << ret << endl;
        }
    }
    return 0;
}