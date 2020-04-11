#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;

int main() {
    int n; 
    cin >> n;
    unordered_map<int, int> mp; 
    vector<int> as(n);
    rep(i, n) {
        cin >> as[i];
        mp[as[i]]++; 
    } 
    ll tot = 0;
    for (auto& p : mp) {
        ll lp = p.second;
        tot += lp * (lp - 1) / 2;
    }
    for (int a : as) {
        cout << tot - mp[a] + 1 << endl;
    }
    return 0;
}