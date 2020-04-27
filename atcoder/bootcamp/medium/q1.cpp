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
    cin >> n;
    vector<int> as(n);
    vector<bool> check(n, false);
    REP(i, n) cin >> as[i];
    int nb = 0, cnt=0;
    int ret = -1; 
    while (true) {
        check[nb] = true;
        nb = as[nb]-1;
        ++cnt;
        if (nb == 1) {
            ret = cnt;
            break;
        }
        if (check[nb]) break;
    } 
    cout << ret << endl;
    return 0;
}