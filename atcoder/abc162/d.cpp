#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n; 
    string s;
    cin >> n;
    cin >> s;
    using vi = vector<int>;
    vector<vi> mp(n, vector<int>(3, 0));
    REP(i, n) {
        int c;
        if (i > 0) mp[i] = mp[i-1];
        if (s[i] == 'R') c = 0; 
        else if (s[i] == 'G') c = 1;  
        else c = 2;
        mp[i][c]++;
    }
    ll ret = 0;
    REP(i, n-2) { 
        FOR(j, i+1, n-1) {
            int t = 2*j-i;
            if ((s[i] == 'R' && s[j] == 'B') 
             || (s[i] == 'B' && s[j] == 'R')) {
                ret += mp[n-1][1] - mp[j][1];
                if (t < n && s[t] == 'G') ret--;
            } 
            if ((s[i] == 'B' && s[j] == 'G') 
             || (s[i] == 'G' && s[j] == 'B')) {
                ret += mp[n-1][0] - mp[j][0];
                if (t < n && s[t] == 'R') ret--;
            }  
            if ((s[i] == 'R' && s[j] == 'G') 
             || (s[i] == 'G' && s[j] == 'R')) {
                ret += mp[n-1][2] - mp[j][2];
                if (t < n && s[t] == 'B') ret--;
            }  
        }
    }
    cout << ret << endl;
    return 0;
}