#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    string s;
    cin >> s;
    ll bc = 0, ret = 0;
    for(char c : s) {
        if (c == 'W') ret += bc;
        else ++bc; 
    }
    cout << ret << endl;
    return 0;
}