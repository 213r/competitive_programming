#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());

    rep(i, x) r.push_back(p[i]);
    rep(i, y) r.push_back(q[i]);
    sort(r.begin(), r.end(), greater<int>());
    ll ret = 0;
    rep(i, x+y) ret += r[i];
    cout << ret << endl;
    return 0;
}