#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int as[10][10];
ll calc_value(vector<vector<int>>& cs) {
    ll score = 0;
    for (auto& v : cs) {
        int s = v.size();
        if (s < 2) continue;
        REP(i, s-1) {
            FOR(j, i+1, s) {
                score += as[v[i]][v[j]];
            }
        }
    }
    return score;
}

int main() {
    int n;
    cin >> n;
    REP(i, n-1) {
        FOR(j, i+1, n) {
            cin >> as[i][j];
            as[j][i] = as[i][j]; 
        }
    }

    int tot = pow(3, n);
    ll ms = -1e18;
    REP(c, tot) {
        vector<vector<int>> cands(3, vector<int>());
        int c1 = c; 
        REP(i, n) {
            cands[c1%3].push_back(i);
            c1 /= 3;
        }
        ll sc = calc_value(cands);
        ms = max(ms, sc); 
    } 
    cout << ms << endl;
    return 0;
}