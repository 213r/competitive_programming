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
    int h, w;
    cin >> h >> w;
    vector<string> mp; 
    rep(i, h) {
        string s; cin >> s;
        mp.emplace_back(s);
    }
    rep(i, h) {
        rep(j, w) {
            if (mp[i][j] == '#') {
                if (!((i > 0  && mp[i-1][j] == '#')
                || (i < h-1 && mp[i+1][j] == '#')
                || (j > 0   && mp[i][j-1] == '#')
                || (j < w-1 && mp[i][j+1] == '#'))) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    } 
    cout << "Yes" << endl;
    return 0;
}