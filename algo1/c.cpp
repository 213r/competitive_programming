#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    vector<int> vs(6);
    REP(i, 6) cin >> vs[i];
    sort(vs.begin(), vs.end());
    cout << vs[3] << endl; 
    return 0;
}