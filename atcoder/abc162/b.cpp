#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

ll csum(ll n) {
    return n * (n+1) / 2;
}

int main() {
    ll n; 
    cin >> n;
    ll ret = csum(n);
    ret -= csum(n/3)*3;
    ret -= csum(n/5)*5;
    ret += csum(n/15)*15;
    cout << ret << endl; 
    return 0;
}