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
    vector<string> ms;
    rep(i, h) {
        string s; cin >> s;
        ms.emplace_back(s);
    }
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1,-1,-1,  0, 0,  1, 1, 1};
    rep(i, h) {
        rep(j, w) {
            int cnt = 0;
            if (ms[i][j] == '.') {
                rep(k, 8) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < h && y >= 0 && y < w && ms[x][y]=='#') ++cnt;
                }
                ms[i][j] = cnt + '0'; 
            } 
        }
    }
    for (auto& l : ms) {
        cout << l << endl;
    }
    return 0;
}