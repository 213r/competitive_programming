#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
typedef long long ll;
const int MOD = 1000000007; 

const int MAX = 700000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    COMinit();
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

 
int main() {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    int d = y - x;
    if (d > x) cout << 0 << endl;
    else if (d == x) cout << 1 << endl;
    else {
        if ((x-d)%3!=0) cout << 0 << endl;
        else {
            int s = (x-d)/3;
            int b = s + d;
            cout << COM(s+b, s) << endl;
        }
    }

    return 0;
}