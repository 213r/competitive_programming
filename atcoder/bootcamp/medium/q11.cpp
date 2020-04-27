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
    int n, m;
    cin >> n >> m;
    using pii=pair<int, int>;
    vector<pii> st,ch;
    rep(i, n) {
        int a, b; cin >> a >> b;
        st.emplace_back(a,b); 
    }
    rep(i, m) {
        int c, d; cin >> c >> d;
        ch.emplace_back(c,d); 
    }
    for(auto& s : st) {
        int d = numeric_limits<int>::max(), mi;
        rep(i, m) {
            auto& c = ch[i]; 
            int tmp = abs(s.first - c.first) 
                + abs(s.second-c.second);
            if (d > tmp) {
                mi = i+1;
                d = tmp;
            }
        }
        cout << mi << endl; 
    }
    
    return 0;
}