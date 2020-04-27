#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    string n; 
    cin >> n;
    string ans = "No";
    REP(i, 3) if (n[i] == '7') ans = "Yes";
    cout << ans << endl; 
    return 0;
}