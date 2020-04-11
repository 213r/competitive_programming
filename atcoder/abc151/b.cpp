#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n,k,m, tot=0; 
    cin >> n >> k >> m;
    rep(i, n-1) {
        int a;
        cin >> a;
        tot += a;
    }
    int ret = n*m - tot;
    if (ret < 0) ret = 0;
    if (ret > k) ret = -1;
    cout << ret << endl;
    return 0;
}