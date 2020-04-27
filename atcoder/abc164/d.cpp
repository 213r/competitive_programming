#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const int MOD = 1000000007; 


int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n < 4) {
        cout << 0 << endl;
        return 0;
    }
    int keta = 1, bnum=0; 
    unordered_map<int, ll> mp;
    per(i, n) {
        int c = s[i] - '0';
        bnum += c*keta%2019;
        bnum %= 2019;
        keta = keta*10%2019;
        mp[bnum]++; 
    }
    ll ret = 0;
    for (auto& p : mp) {
        ll c = p.second;
        ret += c*(c-1)/2; 
        if (p.first==0) ret += c; 
    }
    cout << ret << endl;
    return 0;
}