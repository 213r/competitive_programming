#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    ll n, m;
    cin >> n >> m;
    int tot = 0;
    vector<int> as(n);
    rep(i, n) {
        cin >> as[i];
        tot += as[i];
    }
    int cnt = 0;
    rep(i, n) {
        if (as[i] * 4 * m >= tot) ++cnt;
    }
    if (cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}