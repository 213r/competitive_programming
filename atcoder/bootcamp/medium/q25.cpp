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
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> as;
    rep(i, n) {
        int a; cin >> a;
        as[a]++;
    }
    int m = as.size();
    int ret = 0;
    if (m > k) {
        vector<pair<int, int>> av(as.begin(), as.end());
        sort(av.begin(), av.end(), [](const auto& p1, const auto& p2){ return p1.second < p2.second;});
        rep(i, m-k) ret += av[i].second;
    }
    cout << ret << endl;
    return 0;
}