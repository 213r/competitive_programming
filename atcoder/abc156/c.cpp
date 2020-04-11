#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 


int main() {
    int n;
    cin >> n;
    double r;
    vector<int> xs(n);
    rep(i, n) {
        cin >> xs[i];
        r += xs[i]; 
    }
    r /= n;
    int ri = static_cast<int>(r);
    if (r - ri > 0.5) ri += 1;
    int ret = 0;
    rep(i, n) {
        ret += (xs[i] - ri) * (xs[i] - ri);
    }
    cout << ret << endl;
}