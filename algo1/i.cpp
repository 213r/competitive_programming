#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    int tc = 1 << n; 
    vector<ll> dp(tc, INF);
    dp[0] = 0;
    REP(i, m) {
        string s;
        int c;
        cin >> s >> c;
        int bit = 0;
        REP(j, n) if (s[j] == 'Y') bit += 1 << j;
        REP(j, tc) {
            if (dp[j] > -1)  dp[j|bit] = min(dp[j|bit], dp[j] + c);
        }
    }
    int ret = (dp[tc-1] == INF) ? -1 : dp[tc-1]; 
    cout << ret << endl;
    return 0;
}