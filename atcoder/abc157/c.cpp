#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n, m;
    cin >> n >> m;
    bool isout = false;
    vector<int> vs(n, -1);
    rep(i, m) {
        int s, c;
        cin >> s >> c;
        s--;
        if (vs[s] >= 0 && vs[s] != c) isout = true; 
        else vs[s] = c;
    } 
    if (n > 1 && vs[0] == 0) isout = true; 
    if (isout) {
        cout << -1 << endl; 
        return 0;
    }
    int ret = 0;
    int keta = 1; 
    rep(i, n) {
        int idx = n-i-1;
        // cout << vs[idx] << endl;
        if (n > 1 && idx == 0) {
            ret += keta * max(vs[idx], 1); 
        } else {
            ret += keta * max(vs[idx], 0); 
        }
        keta *= 10;
    }
    cout << ret << endl;
    return 0;
}