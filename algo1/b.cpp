#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n;
    cin >> n;
    vector<int> as(n);
    REP(i, n) cin >> as[i];
    REP(i, n-1) {
        int da = as[i+1] - as[i];
        if (da < 0) cout << "down " << -da << endl;
        else if(da == 0) cout << "stay" << endl;
        else cout << "up " << da << endl;
    }
    return 0;
}