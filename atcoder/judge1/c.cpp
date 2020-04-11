#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 
int main() {
    vector<int> as(3);
    REP(i, 3) cin >> as[i];
    vector<vector<int>> dp(3, vector<int>(3, 10));
    dp[0][0] = 1;
    int n = as[0] + as[1] + as[2];
    vector<int> tmp(n-1);
    FOR(i, 2, n+1) tmp[i-2] = i;
    int cnt = 0;
    do {
        int ti = 0;
        FOR(i, 1, 9) {
            int l = i/3, c = i%3;
            if (as[c] - 1 < l) continue; 
            dp[l][c] = tmp[ti++];
            if (ti == tmp.size()) break;
        }
        /*
        REP(i, 3) {
            REP(j, 3)  cout << dp[i][j] << " "; 
            cout << endl;
        }
        cout << "************" << endl;;
        */
        if (dp[0][0] <= dp[0][1] && dp[0][1] <= dp[0][2]
         && dp[1][0] <= dp[1][1] && dp[1][1] <= dp[1][2]
         && dp[2][0] <= dp[2][1] && dp[2][1] <= dp[2][2]
         && dp[0][0] <= dp[1][0] && dp[1][0] <= dp[2][0]
         && dp[0][1] <= dp[1][1] && dp[1][1] <= dp[2][1]
         && dp[0][2] <= dp[1][2] && dp[1][2] <= dp[2][2]
        ) cnt++; 
    } while(next_permutation(tmp.begin(), tmp.end()));
    cout << cnt << endl;
    return 0;
}
