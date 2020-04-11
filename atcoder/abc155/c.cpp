#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n, mc = 0;
    cin >> n;
    unordered_map<string, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        mp[s] += 1;
        mc = max(mc ,mp[s]);
    }
    vector<string> vm;
    for (auto& p : mp)  {
        if (p.second == mc) vm.push_back(p.first);
    }
    sort(vm.begin(), vm.end());
    for (auto& v : vm) {
        cout << v << endl;
    }
    return 0;
}