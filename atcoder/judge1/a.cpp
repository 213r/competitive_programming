#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int s, l, r;
    cin >> s >> l >> r;
    cout << min(max(s, l), r) << endl;
    return 0;
}