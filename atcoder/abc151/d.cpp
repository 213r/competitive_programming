#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int h,w; 
    cin >> h >> w;
    vector<vector<bool>> mazes(h, vector<bool>(w, false));
    rep(i, h) {
        rep(j, w) {
            char s;
            cin >> s;
            if (s == '.') mazes[i][j] = true;
    }
    
    return 0;
}